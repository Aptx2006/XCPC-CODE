#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

i64 T = 1, n, m, k, ans, buc;

void solve() {
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];

    bool ok = 1;
    vector<int> bb = b;          
    vector<bool> vis(n + 1, 0);

    vector<int> id(n + 1, -1), sz(n + 1, 0);
    vector<vector<int>> G;
    for(int i = 1; i <= n; i++) {
        if(id[i] != -1) continue;
        vector<int> c;
        int x = i;
        while(id[x] == -1) {
            id[x] = G.size();
            c.push_back(x);
            x = a[x];
        }
        int L = c.size();
        for(int v : c) sz[v] = L;
        G.push_back(c);
    }

    for(int i = 1; i <= n; i++) {
        if(b[i] == -1) continue;
        int x = i, y = b[i];
        for(int t = 0; t < sz[i]; t++) {
            if(bb[x] != -1 and bb[x] != y) { 
                ok = 0; 
                break; 
            }
            bb[x] = y;
            x = a[x];
            y = a[y];
        }
        if(!ok) break;
    }

    if(ok) {
        vector<int> isok(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            if(bb[i] != -1) {
                if(++isok[bb[i]] > 1) { 
                    ok = false; 
                    break; 
                }
            }
        }
    }

    if(!ok) {
        cout << "NO\n";
        return;
    }

    vector<bool> used(n + 1, 0);
    for(int i = 1; i <= n; i++)
        if(bb[i] != -1) used[bb[i]] = 1;

//    for(int i = 1; i <= n; i++) {
//        if(bb[i] == -1) {
//            for(int v = 1; v <= n; v++) {
//                if(!used[v]) {
//                    bb[i] = v;
//                    used[v] = 1;
//                    break;
//                }
//            }
//        }
//    }

        for(int i = 1; i <= n; i++) {
            if(bb[i] == -1) {
                bool flag = false;
                for(int v = 1; v <= n; v++) {
                    if(!used[v]) {
                        int x = i, y = v;
                        bool bad = false;
                        for(int t = 0; t < sz[i]; t++) {
                            if(bb[x] != -1 and bb[x] != y) { 
                                bad = true; 
                                break; 
                            }
                            if(used[y] and bb[x] != y) { 
                                bad = true; 
                                break; 
                            }
                            x = a[x];
                            y = a[y];
                        }
                    if(!bad) {
                        x = i, y = v;
                        for(int t = 0; t < sz[i]; t++) {
                            bb[x] = y;
                            used[y] = 1;
                            x = a[x];
                            y = a[y];
                        }
                        flag = true;
                        break;
                    }
                }
            }
            if(!flag) { 
                ok = false; 
                break; 
            }
        }
    }    
    if(!ok) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for(int i = 1; i <= n; i++) cout << bb[i] << " \n"[i == n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}