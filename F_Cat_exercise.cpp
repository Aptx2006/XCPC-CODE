#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize(2)
/*i32 : -2e9~2e9
i64: -9e18~9e18
u64: 0~1.8e19*/
using i64 = long long;
using u64 = unsigned long long;
#define dbg(A) cout << #A << "==" << A << '\n';
#define all(A) A.begin(), A.end()
//#define int long long

const int MAXn = 1E5 + 5, MOD = 1E9 + 7, InF = 1E18;

int n, m, t, ar[MAXn], ans, cnt, k;

void solve() { 
    cin >> n;
    vector<int> P(n + 1);  // P[i] 是第i个塔的高度（i从1到n）
    vector<int> pos(n + 1); // pos[h] 是高度h的塔的位置
    for (int i = 1; i <= n; ++i) {
        cin >> P[i];
        pos[P[i]] = i;
    }

    // 初始位置：高度为n的塔的位置
    int s = pos[n];
    vector<int> left, right;

    // 收集左侧（<s）和右侧（>s）的位置
    for (int i = 1; i <= n; ++i) {
        if (i == s) continue;
        if (i < s) {
            left.push_back(i);
        } else {
            right.push_back(i);
        }
    }

    // 左侧按降序排列（离s由近到远），右侧按升序排列（离s由近到远）
    sort(left.rbegin(), left.rend());
    sort(right.begin(), right.end());

    long long total = 0;
    int curr = s;
    int l_ptr = 0, r_ptr = 0;
    int l_size = left.size(), r_size = right.size();

    while (l_ptr < l_size || r_ptr < r_size) {
        bool choose_left = false;
        if (l_ptr < l_size && r_ptr < r_size) {
            // 左右都有，选距离更远的
            long long d_l = curr - left[l_ptr];
            long long d_r = right[r_ptr] - curr;
            if (d_l > d_r) {
                choose_left = true;
            }
        } else if (l_ptr < l_size) {
            // 只有左侧
            choose_left = true;
        } else {
            // 只有右侧
            choose_left = false;
        }

        if (choose_left) {
            total += curr - left[l_ptr];
            curr = left[l_ptr];
            l_ptr++;
        } else {
            total += right[r_ptr] - curr;
            curr = right[r_ptr];
            r_ptr++;
        }
    }

    cout << total << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int times = 1;// cin >> times;
    while (times--) solve();
    return 0;
}
