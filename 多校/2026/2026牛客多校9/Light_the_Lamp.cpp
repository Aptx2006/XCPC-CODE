#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

i64 T = 1, n, m, k, ans, cnt;

/*
1 2
3 4
*/
struct nod {
    i64 x, y;
    i64 time1, time2, time3, time4;
    i64 len;
};

void solve() {
    cin >> n;
    vector<i64> a(n);
    for(auto &x: a) cin >> x;
    stack<nod> st;
    ans = 0;
    for(int i = 1; i <= n; i++) {
        nod cur = {i, a[i - 1], 0, 0, 0, 0, 1};
        while(!st.empty()) {
            nod top = st.top();
            if(top.x + top.len == cur.x and top.y + top.len == cur.y) {
                st.pop();
                i64 t = max(top.time4, cur.time1); 
                nod nxt;
                nxt.x = top.x;
                nxt.y = top.y;
                nxt.len = top.len + cur.len;
                nxt.time1 = top.time1;            
                nxt.time4 = cur.time4;             
                nxt.time2 = max({t + nxt.len - 1, top.time2 + cur.len, cur.time2 + top.len});       
                nxt.time3 = max({t + nxt.len - 1, top.time3 + cur.len, cur.time3 + top.len});      
                cur = nxt;
            }
            else if(top.x + top.len == cur.x and cur.y + cur.len == top.y) {
                st.pop();
                i64 t = max(top.time3, cur.time2); 
                nod nxt;
                nxt.x = top.x;
                nxt.y = cur.y;
                nxt.len = top.len + cur.len;
                nxt.time2 = top.time2;            
                nxt.time3 = cur.time3;         
                nxt.time1 = max({t + nxt.len - 1, top.time1 + cur.len, cur.time1 + top.len});       
                nxt.time4 = max({t + nxt.len - 1, top.time4 + cur.len, cur.time4 + top.len});       
                cur = nxt;
            } 
            else {
                break;
            }
        }
        st.push(cur);
    }
    
    if(st.size() == 1) {
        nod res = st.top();
        cout << max({res.time1, res.time2, res.time3, res.time4}) << "\n";
    } else {
        cout << -1 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(; T--; solve());
    return 0;
}
