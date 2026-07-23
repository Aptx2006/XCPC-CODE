#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;
set<char> st = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

void solve() {
    string s;
    cin >> s;
    if(s.size() == 8 and st.count(s[1]) and st.count(s[3]) 
        and st.count(s[5]) and st.count(s[7])
        and !st.count(s[0]) and !st.count(s[2]) 
        and !st.count(s[4]) and !st.count(s[6])) {
        cout << "Suspected Virus\n";
    }else {
        cout << "Well-Being\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
