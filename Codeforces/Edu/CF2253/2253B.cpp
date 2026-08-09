#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;

void solve() {
    cin >> n;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    vector<int> b,len;
    
    for(int i = 0; i < n; i++) {
        if(b.empty() or a[i] != b.back()) {
            b.push_back(a[i]);
            len.push_back(1);
        }else {
            len.back()++;
        }
    }
    
    int ans = b.size();
    
    for(int i = 0; i < ans - 1; i++) {
        if(len[i] >= 2 and len[i+1] >= 2) {
            cout << ans + 2 << "\n";
            return;
        }
    }

    for(int i = 0; i < ans; i++) {
        if(len[i] >= 2) {
            if(i < ans - 1) {
                if(i + 2 >= ans or b[i +  2] != b[i]) {
                    cout << ans + 1 << "\n";
                    return; 
                }
            }
            if(i > 0) {
                if(i - 2 < 0 or b[i - 2] != b[i]) {
                    cout << ans + 1 << "\n";
                    return;
                }
            }
        }
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
