#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;
const int mod = 998244353;

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
    db x = 0, y = 0;
    int u = 0, v = 0; 
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

}

using namespace geometry;

void solve() {
    cin >> n;
    vector<Point> a(n + 1);
    vector<int> type(n + 1);
    int cnt0 = 0, cnt1 = 0;
    
    for(int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y >> type[i];
        if(type[i] == 0) cnt0++;
        else cnt1++;
    }
    vector<Point> b;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (type[i] != type[j]) {
                Point p = a[j] - a[i];
                p.u = i;
                p.v = j;
                b.push_back(p);
            }
        }
    }
    polarSort(b);
    int dp[505][505]{0};   
    bool isok[505][505]{0};
    vector<int> G[505];
    for(auto& e : b) {
        int u = e.u, v = e.v;
        for(auto c : G[u]) {
            if(c == u) continue;
            if(!isok[v][c]) {
                isok[v][c] = 1;
                G[v].push_back(c);
            }
            (dp[v][c] += dp[u][c]) %= mod;
        }
        if(!isok[v][u]) {
            isok[v][u] = 1;
            G[v].push_back(u);
        }
        dp[v][u] += 1;
    }
    i64 sum = 0;
    for(int i = 1; i <= n; i++) {
        sum = (sum + dp[i][i]) % mod;
    }
    sum = (sum - cnt0 * cnt1 % mod + mod) % mod;
    cout << sum << "\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
