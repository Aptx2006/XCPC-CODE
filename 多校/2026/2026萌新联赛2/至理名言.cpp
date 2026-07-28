#include<bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using pbset = tree<string, null_type, less<string>, rb_tree_tag, tree_order_statistics_node_update>;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;

void solve() {
    cin >> n;
    unordered_map<string, int> mp;
    set<string> st;
    for(int i = 0 ; i < n; i++) {
        int op;
        string s;
        cin >> op >> s;
        if(op == 1) {
            if(mp[s] == 0) st.insert(s);
            cout << ++ mp[s] << '\n';
        }else if(op == 2) {
            auto it = st.lower_bound(s);
            if(it != st.end()) {
                string ss = s;
                ss += '{';
                if(*it < ss) {
                    cout << "YES\n";
                    continue;
                }
            }
            cout << "NO\n";
        }else {
            if(mp[s] > 0) {
                st.erase(s);
                mp[s] = 0;
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
