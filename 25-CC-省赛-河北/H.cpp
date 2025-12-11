#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128_t;

const i64 N = 2e5 + 5, M = 1e9 + 7;
i64 n, m;
string s, ts;

void solve() {
    getline(cin, ts);
    for(auto &x : ts) {
        if(isupper(x)) s += char(x + 'a' - 'A');
        else if(islower(x)) s += x; 
    }
    n = s.size();
    if(n < 13) cout << "No\n";
    else {
        if( s.substr(n - 12) == "isallyouneed" ) {
            cout << "Yes\n";
            for(int i = 0;i < n - 12; i++) 
                cout << s[i];
        }else {
            cout << "No\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; //cin >> T;
    while(T--) solve();
}
