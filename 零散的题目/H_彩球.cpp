#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int N = 1e5 + 5;
int op, q, c, v, mx[N];
stack< pair<int,int> > st, tag;
i64 sum;

void solve() {
    cin >> q;
    while(q--) {
        cin >> op;
        if(op == 1) {
            cin >> c >> v;
            st.push({c, v});
            if(mx[c] <= v) {
                tag.push({c, mx[c]});
                sum += v - mx[c];
                mx[c] = v;
            }else {
                tag.push({-1, -1});
            }
        }else if(op == 2) {
            st.pop();
            auto [c1, v1] = tag.top();
            tag.pop();
            if(c1 != -1) {
                sum += v1 - mx[c1];
                mx[c1] = v1;
            }
        }else cout << sum << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
