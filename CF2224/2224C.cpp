#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

using i64 = long long;
#define all(x) (x).begin(),(x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T, n, m, k, ans, cnt;

void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    
    int A = 0, B = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            if (a[i] == '(') {
                A++;
                B++;
            } else {
                A--;
                B--;
            }
        } else {
            if (A < B) {
                A++;
                B--;
            } else {
                A--;
                B++;
            }
        }
        
        if (A < 0 or B < 0) {
            cout << "NO\n";
            return;
        }
    }
    
    if (A == 0 and B == 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    solve();
}
