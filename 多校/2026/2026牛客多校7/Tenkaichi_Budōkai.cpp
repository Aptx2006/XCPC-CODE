#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;

void solve() {
    int x;
    cin >> n >> x;
    vector<int> p(n + 1), q(n + 1), posp(n + 1), posq(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
        posp[p[i]] = i;
    }
    for(int i = 1; i <= n; i++) {
        cin >> q[i];
        posq[q[i]] = i;
    }
    
    vector<bool> dead(n + 1, 0);
    int p1 = 1, q1 = 1;
    vector<int> ans;
    
    while((int)ans.size() < n - 1) {
        if(p1 > n or q1 > n) {
            cout << "NO\n";
            return;
        } 
        int u = p[p1], v = q[q1];
        
        if(u == v) {
            cout << "NO\n";
            return;
        }
        
        bool oku = false;
        
        if(u == x) {
            oku = false;
        } else if(v == x) {
            oku = true;
        } else {
            if (posq[u] < posp[v]) {
                oku = true;
            } else {
                oku = false;
            }
        }
        if(oku) {
            ans.push_back(u);
            dead[u] = 1;
        } else {
            ans.push_back(v);
            dead[v] = 1;
        }

        while(p1 <= n and dead[p[p1]]) p1++;
        while(q1 <= n and dead[q[q1]]) q1++;
    }

    cout << "YES\n";
    for(auto &x: ans) cout << x << ' ';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(; T--; solve());
    return 0;
}
