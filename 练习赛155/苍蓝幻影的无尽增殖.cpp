#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;

void solve() {
    cin >> n >> m;
    string s;
    cin >> s;
    
    vector<int> buc(26, 0);
    for(auto ch : s) {
        if(ch >= 'a' and ch <= 'z') {
            buc[ch - 'a']++;
        }
    }
    
    vector<int> pos; 
    bool flag = false; 

    while(m--) {
        int op;
        cin >> op;
        if(op == 1) {
            char c;
            cin >> c;
            if(flag) continue; 
            if(buc[c - 'a'] == 0) continue; 

            string ns = "";
            ns.reserve(s.length() * 2);
            for(char ch : s) {
                ns += ch;
                if(ch == c) {
                    ns += "Fantasy_Blue";
                }
            }
            
            vector<int> npos;
            auto id = ns.find("Fantasy_Blue", 0);
            while(id != string::npos) {
                npos.push_back(id + 1);
                id = ns.find("Fantasy_Blue", id + 1);
            }
            
            if((int)npos.size() > 114514) {
                flag = true;
                s.clear(); 
                pos.clear(); 
            } else {
                s = move(ns);
                pos = move(npos);
                
                fill(all(buc), 0);
                for(auto ch : s) {
                    if(ch >= 'a' and ch <= 'z') {
                        buc[ch - 'a']++;
                    }
                }
            }
        } else {
            i64 L, R;
            cin >> L >> R;
            if(flag) {
                cout << "sto Fantasy_Blue orz\n";
            } else {
                i64 len = s.size();
                L = min(L, len);
                R = min(R, len);
                
                if(L > R or R - L + 1 < 12) {
                    cout << 0 << "\n";
                } else {
                    auto it1 = lower_bound(all(pos), L);
                    auto it2 = upper_bound(all(pos), R - 11);
                    cout << it2 - it1 << "\n";
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(; T--; solve());
    return 0;
}
