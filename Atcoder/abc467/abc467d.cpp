#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;

namespace geometry {

using db = double;

constexpr db EPS = 1e-9;
const db PI = acos(-1.0);
const db INF = numeric_limits<db>::infinity();

int sgn(db x) {
    if (x < -EPS) return -1;
    if (x > EPS) return 1;
    return 0;
}

db clampUnit(db x) {
    return max(-1.0, min(1.0, x));
}

struct Point {
    i64 x = 0, y = 0;

    Point() = default;
    Point(db x, db y) : x(x), y(y) {}

    Point operator+ (const Point& p) const { return {x + p.x, y + p.y}; }
    Point operator- (const Point& p) const { return {x - p.x, y - p.y}; }
    Point operator* (db k) const { return {x * k, y * k}; }
    Point operator/ (db k) const { return {x / k, y / k}; }

    Point& operator+= (const Point& p) {
        x += p.x;
        y += p.y;
        return *this;
    }

    Point& operator-= (const Point& p) {
        x -= p.x;
        y -= p.y;
        return *this;
    }

    // 仅用于 sort：不能在比较器中使用 EPS。
    bool operator< (const Point& p) const {
        return x != p.x ? x < p.x : y < p.y;
    }

    bool operator== (const Point& p) const {
        return sgn(x - p.x) == 0 && sgn(y - p.y) == 0;
    }

    bool operator!= (const Point& p) const {
        return !(*this == p);
    }
};

using Vector = Point;

Point operator* (db k, const Point& p) {
    return p * k;
}

// 点积：a·b = |a||b|cos(theta)。
db dot(Vector a, Vector b) {
    return a.x * b.x + a.y * b.y;
}

// 叉积：a×b = |a||b|sin(theta)。
db cross(Vector a, Vector b) {
    return a.x * b.y - a.y * b.x;
}

// 有向面积的两倍：(b-a)×(c-a)。
db cross(Point a, Point b, Point c) {
    return cross(b - a, c - a);
}

db length2(Vector a) {
    return dot(a, a);
}

db length(Vector a) {
    return sqrt(length2(a));
}

db distance(Point a, Point b) {
    return length(a - b);
}

// 零向量没有单位向量，调用前应保证 length(a) > EPS。
Vector normalize(Vector a) {
    return a / length(a);
}

// 返回两个非零向量的夹角，范围 [0, PI]。
db angle(Vector a, Vector b) {
    return acos(clampUnit(dot(a, b) / length(a) / length(b)));
}

// 返回从 a 逆时针转到 b 的有向角，范围 [-PI, PI]。
db directedAngle(Vector a, Vector b) {
    return atan2(cross(a, b), dot(a, b));
}

// 将向量逆时针旋转 rad。
Vector rotate(Vector a, db rad) {
    db c = cos(rad), s = sin(rad);
    return {a.x * c - a.y * s, a.x * s + a.y * c};
}

// 点 c 在有向直线 a->b 左侧返回 1，右侧返回 -1，共线返回 0。
int orientation(Point a, Point b, Point c) {
    return sgn(cross(a, b, c));
}

struct Line {
    Point p;
    Vector v;

    Line() = default;

    // 由直线上一点和方向向量构造。
    Line(Point p, Vector v) : p(p), v(v) {}

    // 由直线上两点构造。
    static Line through(Point a, Point b) {
        return {a, b - a};
    }

    Point point(db t) const {
        return p + v * t;
    }
};

struct Segment {
    Point a, b;
};

// 三点共线。
bool collinear(Point a, Point b, Point c) {
    return orientation(a, b, c) == 0;
}

// 点到直线的距离。要求直线方向向量非零。
db distancePointLine(Point p, const Line& l) {
    return fabs(cross(l.v, p - l.p)) / length(l.v);
}

// 点到线段的距离，允许退化线段。
db distancePointSegment(Point p, Point a, Point b) {
    if (a == b) return distance(p, a);

    Vector ab = b - a;
    if (sgn(dot(ab, p - a)) < 0) return distance(p, a);
    if (sgn(dot(ab, p - b)) > 0) return distance(p, b);
    return fabs(cross(ab, p - a)) / length(ab);
}

// includeEndpoints=true 时包含端点。
bool onSegment(Point p, Point a, Point b, bool includeEndpoints = true) {
    if (orientation(a, b, p) != 0) return false;
    int d = sgn(dot(a - p, b - p));
    return includeEndpoints ? d <= 0 : d < 0;
}

// 无限直线 ab 是否与线段 cd 有公共点。
bool lineIntersectsSegment(Point a, Point b, Point c, Point d) {
    int x = orientation(a, b, c);
    int y = orientation(a, b, d);
    return x == 0 || y == 0 || x != y;
}

// 两闭线段是否相交，包括端点接触与共线重叠。
bool segmentsIntersect(Point a, Point b, Point c, Point d) {
    int abC = orientation(a, b, c);
    int abD = orientation(a, b, d);
    int cdA = orientation(c, d, a);
    int cdB = orientation(c, d, b);

    if (abC == 0 && onSegment(c, a, b)) return true;
    if (abD == 0 && onSegment(d, a, b)) return true;
    if (cdA == 0 && onSegment(a, c, d)) return true;
    if (cdB == 0 && onSegment(b, c, d)) return true;

    return abC * abD < 0 && cdA * cdB < 0;
}

bool parallel(const Line& a, const Line& b) {
    return sgn(cross(a.v, b.v)) == 0;
}

// 求两条不平行直线的唯一交点。
// 平行或重合时返回 false。
bool lineIntersection(const Line& a, const Line& b, Point& out) {
    db det = cross(a.v, b.v);
    if (sgn(det) == 0) return false;

    db t = cross(b.p - a.p, b.v) / det;
    out = a.point(t);
    return true;
}

db triangleSignedArea(Point a, Point b, Point c) {
    return cross(a, b, c) / 2.0;
}

db triangleArea(Point a, Point b, Point c) {
    return fabs(triangleSignedArea(a, b, c));
}

// 海伦公式。叉积公式通常更快、更稳定。
db triangleAreaHeron(Point a, Point b, Point c) {
    db x = distance(a, b);
    db y = distance(a, c);
    db z = distance(b, c);
    db p = (x + y + z) / 2;
    return sqrt(max(0.0, p * (p - x) * (p - y) * (p - z)));
}

// 多边形有向面积：逆时针为正，顺时针为负。
db polygonSignedArea(const vector<Point>& polygon) {
    db area2 = 0;
    int n = static_cast<int>(polygon.size());

    for (int i = 0; i < n; ++i) {
        area2 += cross(polygon[i], polygon[(i + 1) % n]);
    }
    return area2 / 2;
}

db polygonArea(const vector<Point>& polygon) {
    return fabs(polygonSignedArea(polygon));
}

enum class PointPolygonRelation {
    Outside,
    Boundary,
    Inside
};

// 射线法，适用于简单多边形，包括凹多边形。
// 复杂度 O(n)，顶点顺序可顺时针或逆时针。
PointPolygonRelation pointInPolygon(
    Point p,
    const vector<Point>& polygon
) {
    bool inside = false;
    int n = static_cast<int>(polygon.size());

    for (int i = 0, j = n - 1; i < n; j = i++) {
        Point a = polygon[j];
        Point b = polygon[i];

        if (onSegment(p, a, b)) {
            return PointPolygonRelation::Boundary;
        }

        bool crossesY = (a.y > p.y) != (b.y > p.y);
        if (!crossesY) continue;

        db intersectionX =
            a.x + (b.x - a.x) * (p.y - a.y) / (b.y - a.y);

        if (intersectionX > p.x) inside = !inside;
    }

    return inside
        ? PointPolygonRelation::Inside
        : PointPolygonRelation::Outside;
}

// 判断按边界顺序给出的多边形是否为凸多边形。
// strict=false 时允许连续三点共线。
bool isConvex(const vector<Point>& polygon, bool strict = false) {
    int n = static_cast<int>(polygon.size());
    if (n < 3) return false;

    int direction = 0;
    for (int i = 0; i < n; ++i) {
        int turn = orientation(
            polygon[i],
            polygon[(i + 1) % n],
            polygon[(i + 2) % n]
        );

        if (turn == 0) {
            if (strict) return false;
            continue;
        }

        if (direction == 0) direction = turn;
        else if (direction != turn) return false;
    }

    return direction != 0;
}

struct Circle {
    Point center;
    db radius = 0;

    Circle() = default;
    Circle(Point center, db radius) : center(center), radius(radius) {}

    db area() const {
        return PI * radius * radius;
    }

    db circumference() const {
        return 2 * PI * radius;
    }
};

// 弧长 L = alpha*r，扇形面积 S = alpha*r^2/2。
db sectorArea(Vector a, Vector b, db radius) {
    return radius * radius * directedAngle(a, b) / 2;
}

enum class PointCircleRelation {
    Outside = -1,
    On = 0,
    Inside = 1
};

PointCircleRelation relation(Point p, const Circle& c) {
    int state = sgn(distance(p, c.center) - c.radius);
    if (state > 0) return PointCircleRelation::Outside;
    if (state < 0) return PointCircleRelation::Inside;
    return PointCircleRelation::On;
}

enum class LineCircleRelation {
    Separate = -1,
    Tangent = 0,
    Intersect = 1
};

LineCircleRelation relation(const Line& line, const Circle& c) {
    int state = sgn(distancePointLine(c.center, line) - c.radius);
    if (state > 0) return LineCircleRelation::Separate;
    if (state < 0) return LineCircleRelation::Intersect;
    return LineCircleRelation::Tangent;
}

// 返回直线与圆的交点，数量为 0、1 或 2。
vector<Point> lineCircleIntersections(const Line& line, const Circle& c) {
    db vv = length2(line.v);
    if (sgn(vv) == 0) return {};

    db t = dot(c.center - line.p, line.v) / vv;
    Point projection = line.point(t);
    db h2 = c.radius * c.radius - length2(projection - c.center);

    if (sgn(h2) < 0) return {};
    if (sgn(h2) == 0) return {projection};

    Vector offset = normalize(line.v) * sqrt(max(0.0, h2));
    return {projection - offset, projection + offset};
}

enum class CircleCircleRelation {
    Separate,
    ExternallyTangent,
    Intersect,
    InternallyTangent,
    Contained,
    Coincident
};

CircleCircleRelation relation(const Circle& a, const Circle& b) {
    db d = distance(a.center, b.center);

    if (sgn(d) == 0 && sgn(a.radius - b.radius) == 0) {
        return CircleCircleRelation::Coincident;
    }

    if (sgn(d - (a.radius + b.radius)) > 0) {
        return CircleCircleRelation::Separate;
    }

    if (sgn(d - (a.radius + b.radius)) == 0) {
        return CircleCircleRelation::ExternallyTangent;
    }

    db radiusDifference = fabs(a.radius - b.radius);

    if (sgn(d - radiusDifference) < 0) {
        return CircleCircleRelation::Contained;
    }

    if (sgn(d - radiusDifference) == 0) {
        return CircleCircleRelation::InternallyTangent;
    }

    return CircleCircleRelation::Intersect;
}

// 返回两圆的有限交点。
// 重合圆有无穷多个交点，此时返回空数组并应单独判断 relation。
vector<Point> circleCircleIntersections(const Circle& a, const Circle& b) {
    db d = distance(a.center, b.center);

    if (sgn(d) == 0) return {};
    if (sgn(d - a.radius - b.radius) > 0) return {};
    if (sgn(d - fabs(a.radius - b.radius)) < 0) return {};

    db x =
        (a.radius * a.radius - b.radius * b.radius + d * d) /
        (2 * d);

    db h2 = a.radius * a.radius - x * x;
    Vector direction = (b.center - a.center) / d;
    Point base = a.center + direction * x;

    if (sgn(h2) == 0) return {base};

    Vector normal = rotate(direction, PI / 2) * sqrt(max(0.0, h2));
    return {base - normal, base + normal};
}

// 返回点到圆的切点，数量为 0、1 或 2。
vector<Point> tangentPoints(Point p, const Circle& c) {
    Vector v = p - c.center;
    db d2 = length2(v);
    db r2 = c.radius * c.radius;

    if (sgn(d2 - r2) < 0) return {};
    if (sgn(d2 - r2) == 0) return {p};

    Point base = c.center + v * (r2 / d2);
    Vector offset =
        rotate(v, PI / 2) *
        (c.radius * sqrt(max(0.0, d2 - r2)) / d2);

    return {base - offset, base + offset};
}

// 三点外接圆。三点共线时返回 false。
bool circumcircle(Point a, Point b, Point c, Circle& out) {
    Vector u = b - a;
    Vector v = c - a;
    db determinant = 2 * cross(u, v);

    if (sgn(determinant) == 0) return false;

    db uu = length2(u);
    db vv = length2(v);

    Point center{
        a.x + (v.y * uu - u.y * vv) / determinant,
        a.y + (u.x * vv - v.x * uu) / determinant
    };

    out = Circle(center, distance(center, a));
    return true;
}

// 三角形内切圆。三点共线时返回 false。
bool incircle(Point a, Point b, Point c, Circle& out) {
    db sideA = distance(b, c);
    db sideB = distance(a, c);
    db sideC = distance(a, b);
    db perimeter = sideA + sideB + sideC;

    if (sgn(perimeter) == 0 || orientation(a, b, c) == 0) {
        return false;
    }

    Point center =
        (a * sideA + b * sideB + c * sideC) / perimeter;

    out = Circle(
        center,
        distancePointLine(center, Line::through(a, b))
    );
    return true;
}

// 极角排序：以 origin 为极点，从 x 轴正方向开始逆时针排序。
// 同方向的点按到极点距离从小到大排列。
void polarSort(vector<Point>& points, Point origin = {0, 0}) {
    auto half = [](Vector v) {
        return v.y > 0 || (v.y == 0 && v.x >= 0) ? 0 : 1;
    };

    sort(points.begin(), points.end(), [&](Point a, Point b) {
        Vector u = a - origin;
        Vector v = b - origin;

        int hu = half(u);
        int hv = half(v);
        if (hu != hv) return hu < hv;

        db product = cross(u, v);
        if (product != 0) return product > 0;
        return length2(u) < length2(v);
    });
}

// Andrew 凸包，复杂度 O(n log n)。
// keepCollinear=false 时删除边上的中间共线点。
vector<Point> convexHull(
    vector<Point> points,
    bool keepCollinear = false
) {
    sort(points.begin(), points.end());
    points.erase(unique(points.begin(), points.end()), points.end());

    int n = static_cast<int>(points.size());
    if (n <= 1) return points;

    vector<Point> hull;

    auto shouldPop = [&](Point a, Point b, Point c) {
        int turn = orientation(a, b, c);
        return keepCollinear ? turn < 0 : turn <= 0;
    };

    for (Point p : points) {
        while (hull.size() >= 2 &&
               shouldPop(hull[hull.size() - 2], hull.back(), p)) {
            hull.pop_back();
        }
        hull.push_back(p);
    }

    size_t lowerSize = hull.size();

    for (int i = n - 2; i >= 0; --i) {
        Point p = points[i];
        while (hull.size() > lowerSize &&
               shouldPop(hull[hull.size() - 2], hull.back(), p)) {
            hull.pop_back();
        }
        hull.push_back(p);
    }

    hull.pop_back();
    return hull;
}

bool contains(const Circle& c, Point p) {
    return sgn(distance(c.center, p) - c.radius) <= 0;
}

Circle diameterCircle(Point a, Point b) {
    Point center = (a + b) / 2;
    return {center, distance(a, b) / 2};
}

// 三个边界点确定的最小覆盖圆。
// 共线时取三对直径圆中能够覆盖三点且半径最小者。
Circle minimumCircleForThree(Point a, Point b, Point c) {
    Circle result;
    if (circumcircle(a, b, c, result)) return result;

    vector<Circle> candidates = {
        diameterCircle(a, b),
        diameterCircle(a, c),
        diameterCircle(b, c)
    };

    Circle best{{0, 0}, INF};
    for (const Circle& candidate : candidates) {
        if (contains(candidate, a) &&
            contains(candidate, b) &&
            contains(candidate, c) &&
            candidate.radius < best.radius) {
            best = candidate;
        }
    }
    return best;
}

// 随机增量最小圆覆盖，期望复杂度 O(n)。
Circle minimumEnclosingCircle(vector<Point> points) {
    if (points.empty()) return {{0, 0}, 0};

    mt19937 rng(
        static_cast<unsigned>(
            chrono::steady_clock::now().time_since_epoch().count()
        )
    );
    shuffle(points.begin(), points.end(), rng);

    Circle result{points[0], 0};

    for (int i = 0; i < static_cast<int>(points.size()); ++i) {
        if (contains(result, points[i])) continue;

        result = {points[i], 0};

        for (int j = 0; j < i; ++j) {
            if (contains(result, points[j])) continue;

            result = diameterCircle(points[i], points[j]);

            for (int k = 0; k < j; ++k) {
                if (contains(result, points[k])) continue;

                result = minimumCircleForThree(
                    points[i],
                    points[j],
                    points[k]
                );
            }
        }
    }

    return result;
}

// 圆面积并，复杂度 O(n^2 log n)。
// 使用每个圆未被其他圆覆盖的边界弧及格林公式求面积。
db circleUnionArea(vector<Circle> circles) {
    vector<Circle> filtered;

    for (int i = 0; i < static_cast<int>(circles.size()); ++i) {
        bool covered = false;

        for (int j = 0; j < static_cast<int>(circles.size()); ++j) {
            if (i == j) continue;

            db d = distance(circles[i].center, circles[j].center);

            if (sgn(
                    d + circles[i].radius - circles[j].radius
                ) <= 0 &&
                (sgn(circles[i].radius - circles[j].radius) < 0 ||
                 i > j)) {
                covered = true;
                break;
            }
        }

        if (!covered && sgn(circles[i].radius) > 0) {
            filtered.push_back(circles[i]);
        }
    }

    db twiceArea = 0;

    for (int i = 0; i < static_cast<int>(filtered.size()); ++i) {
        const Circle& current = filtered[i];
        vector<pair<db, int>> events;
        int active = 0;

        events.push_back({-PI, 0});
        events.push_back({PI, 0});

        for (int j = 0; j < static_cast<int>(filtered.size()); ++j) {
            if (i == j) continue;

            const Circle& other = filtered[j];
            db d = distance(current.center, other.center);

            if (sgn(d - current.radius - other.radius) >= 0) continue;
            if (sgn(d + other.radius - current.radius) <= 0) continue;

            db centerAngle = atan2(
                other.center.y - current.center.y,
                other.center.x - current.center.x
            );

            db delta = acos(clampUnit(
                (current.radius * current.radius + d * d -
                 other.radius * other.radius) /
                (2 * current.radius * d)
            ));

            db left = centerAngle - delta;
            db right = centerAngle + delta;

            while (left < -PI) {
                left += 2 * PI;
                right += 2 * PI;
            }
            while (left >= PI) {
                left -= 2 * PI;
                right -= 2 * PI;
            }

            if (right <= PI) {
                events.push_back({left, 1});
                events.push_back({right, -1});
            } else {
                ++active;
                events.push_back({left, 1});
                events.push_back({PI, -1});
                events.push_back({-PI, 1});
                events.push_back({right - 2 * PI, -1});
            }
        }

        sort(events.begin(), events.end());

        for (int k = 0; k + 1 < static_cast<int>(events.size()); ++k) {
            active += events[k].second;
            db left = events[k].first;
            db right = events[k + 1].first;

            if (active != 0 || right <= left) continue;

            Point o = current.center;
            db r = current.radius;

            twiceArea += r * (
                r * (right - left) +
                o.x * (sin(right) - sin(left)) -
                o.y * (cos(right) - cos(left))
            );
        }
    }

    return fabs(twiceArea) / 2;
}

// 原点圆与有向线段 ab 对面积交的贡献。
db circleTriangleIntersection(Vector a, Vector b, db radius) {
    Vector d = b - a;
    vector<db> cuts = {0, 1};

    db A = dot(d, d);
    db B = 2 * dot(a, d);
    db C = dot(a, a) - radius * radius;
    db discriminant = B * B - 4 * A * C;

    if (sgn(A) != 0 && sgn(discriminant) >= 0) {
        db root = sqrt(max(0.0, discriminant));
        db t1 = (-B - root) / (2 * A);
        db t2 = (-B + root) / (2 * A);

        if (sgn(t1) > 0 && sgn(t1 - 1) < 0) cuts.push_back(t1);
        if (sgn(t2) > 0 && sgn(t2 - 1) < 0) cuts.push_back(t2);
    }

    sort(cuts.begin(), cuts.end());

    db area = 0;

    for (int i = 0; i + 1 < static_cast<int>(cuts.size()); ++i) {
        db left = cuts[i];
        db right = cuts[i + 1];

        Vector u = a + d * left;
        Vector v = a + d * right;
        Vector middle = a + d * ((left + right) / 2);

        if (sgn(length(middle) - radius) <= 0) {
            area += cross(u, v) / 2;
        } else {
            area += radius * radius *
                    atan2(cross(u, v), dot(u, v)) / 2;
        }
    }

    return area;
}

// 圆与简单多边形的面积交，复杂度 O(n)。
db circlePolygonIntersectionArea(
    const Circle& circle,
    const vector<Point>& polygon
) {
    db area = 0;
    int n = static_cast<int>(polygon.size());

    for (int i = 0; i < n; ++i) {
        Vector a = polygon[i] - circle.center;
        Vector b = polygon[(i + 1) % n] - circle.center;
        area += circleTriangleIntersection(a, b, circle.radius);
    }

    return fabs(area);
}

// 通用自适应 Simpson 积分。
template <class Function>
class AdaptiveSimpson {
private:
    Function function;
    db tolerance;
    int maxDepth;

    db simpson(db left, db right, db fLeft, db fMid, db fRight) {
        return (right - left) *
               (fLeft + 4 * fMid + fRight) / 6;
    }

    db solve(
        db left,
        db right,
        db fLeft,
        db fMid,
        db fRight,
        db whole,
        db eps,
        int depth
    ) {
        db middle = (left + right) / 2;
        db leftMiddle = (left + middle) / 2;
        db rightMiddle = (middle + right) / 2;

        db fLeftMiddle = function(leftMiddle);
        db fRightMiddle = function(rightMiddle);

        db leftArea = simpson(
            left,
            middle,
            fLeft,
            fLeftMiddle,
            fMid
        );

        db rightArea = simpson(
            middle,
            right,
            fMid,
            fRightMiddle,
            fRight
        );

        db delta = leftArea + rightArea - whole;

        if (depth <= 0 || fabs(delta) <= 15 * eps) {
            return leftArea + rightArea + delta / 15;
        }

        return solve(
                   left,
                   middle,
                   fLeft,
                   fLeftMiddle,
                   fMid,
                   leftArea,
                   eps / 2,
                   depth - 1
               ) +
               solve(
                   middle,
                   right,
                   fMid,
                   fRightMiddle,
                   fRight,
                   rightArea,
                   eps / 2,
                   depth - 1
               );
    }

public:
    AdaptiveSimpson(
        Function function,
        db tolerance = 1e-9,
        int maxDepth = 25
    )
        : function(function),
          tolerance(tolerance),
          maxDepth(maxDepth) {}

    db integrate(db left, db right) {
        if (left == right) return 0;
        if (left > right) return -integrate(right, left);

        db middle = (left + right) / 2;
        db fLeft = function(left);
        db fMid = function(middle);
        db fRight = function(right);

        db whole = simpson(
            left,
            right,
            fLeft,
            fMid,
            fRight
        );

        return solve(
            left,
            right,
            fLeft,
            fMid,
            fRight,
            whole,
            tolerance,
            maxDepth
        );
    }
};

// 平面最近点对，复杂度 O(n log n)。
db closestPairDistance(vector<Point> points) {
    int n = static_cast<int>(points.size());
    if (n < 2) return INF;

    sort(points.begin(), points.end());
    vector<Point> buffer(n);

    function<db(int, int)> solve = [&](int left, int right) -> db {
        if (right - left <= 3) {
            db answer = INF;

            for (int i = left; i < right; ++i) {
                for (int j = i + 1; j < right; ++j) {
                    answer = min(answer, distance(points[i], points[j]));
                }
            }

            sort(
                points.begin() + left,
                points.begin() + right,
                [](Point a, Point b) {
                    return a.y != b.y ? a.y < b.y : a.x < b.x;
                }
            );

            return answer;
        }

        int middle = (left + right) / 2;
        db middleX = points[middle].x;

        db answer = min(
            solve(left, middle),
            solve(middle, right)
        );

        merge(
            points.begin() + left,
            points.begin() + middle,
            points.begin() + middle,
            points.begin() + right,
            buffer.begin(),
            [](Point a, Point b) {
                return a.y != b.y ? a.y < b.y : a.x < b.x;
            }
        );

        copy(
            buffer.begin(),
            buffer.begin() + (right - left),
            points.begin() + left
        );

        vector<Point> strip;
        strip.reserve(right - left);

        for (int i = left; i < right; ++i) {
            if (fabs(points[i].x - middleX) < answer) {
                strip.push_back(points[i]);
            }
        }

        for (int i = 0; i < static_cast<int>(strip.size()); ++i) {
            for (int j = i + 1;
                 j < static_cast<int>(strip.size()) &&
                 strip[j].y - strip[i].y < answer;
                 ++j) {
                answer = min(answer, distance(strip[i], strip[j]));
            }
        }

        return answer;
    };

    return solve(0, n);
}

} // namespace geometry

using namespace geometry;

void solve() {
    Point P, Q, R, S;
    cin >> P.x >> P.y >> Q.x >> Q.y >> R.x >> R.y >> S.x >> S.y;
    Vector pq = Q - P, rs = S - R;
    Vector mid = { 
        R.x + S.x - P.x - Q.x,
        R.y + S.y - P.y - Q.y
    };
    int ok = 1;
    if (cross(pq, rs) != 0) {
        ok = 1;
    } else {
        ok = (dot(pq, mid) == 0);
    }
    cout << (ok? "Yes" : "No") << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
