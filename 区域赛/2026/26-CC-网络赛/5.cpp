#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>

using namespace std;
#define int long long
#define dbg(A) cout << '\t' << #A << "->" << A << endl;
#define double long double

const double eps = 1e-12;
signed sgn(double x) {
    return x < -eps ? -1 : x > eps;
}

void fun(double a, double b, double c, double &res1, double &res2) {
    if(sgn(a) == 0) {
        res1 = res2 = -c / b;
        return;
    }
    if(sgn(b * b - 4 * a * c) == -1) {
        res1 = res2 = 0;
        return;
    }
    res1 = ( -b + sqrtl(b * b - 4 * a * c)  ) / (2 * a);
    res2 = ( -b - sqrtl(b * b - 4 * a * c)  ) / (2 * a);
}

void solve() {
    double ans = 0;
    double x1, x2, yc, w, u, v;
    cin >> w >> x1 >> x2 >> yc >> u >> v;
    double t1 = yc / v;
    double l = t1 * u + x1, r = t1 * u + x2;
    //dbg(l) dbg(r)
    if(sgn(l) == -1 and sgn(r) == 1) {
        double res1, res2;
        //fun(1, 2, 1, res1, res2);
        //cout << res1 << " " << res2 << endl;
        fun(u * u - v * v, 2 * x1 * u, x1 * x1 + yc * yc, res1, res2);
        double ans1 = 0;
        if(sgn(res1 - t1) == 1 and sgn(res2 - t1) == 1) ans1 = min(res1, res2);
        else if(sgn(res1 - t1) == 1) ans1 = res1;
        else if(sgn(res2 - t1) == 1) ans1 = res2;

        fun(u * u - v * v, 2 * x2 * u, x2 * x2 + yc * yc, res1, res2);
        double ans2 = 0;
        if(sgn(res1 - t1) == 1 and sgn(res2 - t1) == 1) ans2 = min(res1, res2);
        else if(sgn(res1 - t1) == 1) ans2 = res1;
        else if(sgn(res2 - t1) == 1) ans2 = res2;
        
        ans = (w - yc) / v;
        if(sgn(ans1 - t1) == 1 and sgn(ans2 - t1) == 1) ans += min(ans1, ans2);
        else if(sgn(ans1 - t1) == 1) ans += ans1;
        else if(sgn(ans2 - t1) == 1) ans += ans2;
    }else {
        ans = w / v;
    }
    cout << fixed << setprecision(20) << ans << '\n';
}

signed main() {
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}