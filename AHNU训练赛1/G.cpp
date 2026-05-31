#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T, n, m, k, ans, cnt;

typedef struct point {
    double x, y, z;
    point operator ^ (const point &b) {
        return{ y * b.z - z * b.y, 
                z * b.x - x * b.z, 
                x * b.y - y * b.x };
    }
    double operator * (const point &b) {
        return x * b.x + y * b.y + z * b.z;
    }
    double len() const {
        return sqrt(x * x + y * y + z * z);
    }
} Vector;

void solve() {
    double r;
    point p, s, t;
    cin >> r >> p.x >> p.y >> p.z >> s.x >> s.y >> s.z >> t.x >> t.y >> t.z;
    point n = s ^ t; 
    if((n ^ s) * p > 0 and (n ^ t) * p < 0) {
        double d = fabs(n * p / n.len()) / p.len();
        d = max(-1.0, d);
        d = min(1.0, d);
        cout << fixed << setprecision(6) << asin(d) * r << '\n';
    }else {
        double d1 = s * p / s.len() / p.len();
        d1 = max(-1.0, d1);
        d1 = min(1.0, d1);

        double d2 = t * p / t.len() / p.len();
        d2 = max(-1.0, d2);
        d2 = min(1.0, d2);
        
        double ans = min(acos(d1), acos(d2)) * r;

        cout << fixed << setprecision(6) << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
