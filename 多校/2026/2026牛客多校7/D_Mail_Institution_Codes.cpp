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
    getchar();
    vector<vector<string>> a(n);
    for(int i = 0; i < n; i++) {
        string s, w;
        getline(cin, s);
        stringstream ss(s);
        while(ss >> w) {
            a[i].push_back(w);
        }
    }

    vector<int> num(n, 0);            
    vector<bool> vis(n, false); 
    vector<string> res(n);           

    auto fun =  [&](int i, int r) {
        string res = "";
        for (int j = 0; j < (int)a[i].size(); j++) {
            if (j < r) res += a[i][j];      
            else res += a[i][j][0];         
        }
        return res;
    };

    for(int i = 0; i < n; i++) {
        res[i] = fun(i, 0);
    }

    while(1) {
        map<string, int> mp;
        for(int i = 0; i < n; i++) {
            mp[res[i]]++;
        }

        bool flag = true;
        for(int i = 0; i < n; i++) {
            if(!vis[i] and mp[res[i]] == 1) {
                vis[i] = true;
            }
            if(!vis[i]) {
                flag = false;
            }
        }

        if(flag) break;

        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                num[i]++;
                res[i] = fun(i, num[i]);
            }
        }
    }

    for(int i = 0; i < n; i++) {
        cout << res[i] << "\n";
    }
}

int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    for(; T--; solve());
    return 0;
}
