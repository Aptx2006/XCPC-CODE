#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T, n, m, k, ans, cnt;

void solve() {
    cin >> n;
    vector<pair<int, int>> a(n);
    for(auto &[x, y]: a) {
        cin >> x >> y;
    }
    
    sort(all(a), [](const auto& o1, const auto& o2) {
        if (o1.first != o2.first) return o1.first < o2.first;
        return o2.second > o2.second;
    });
    
    vector<pair<int, int>> b;
    for (auto& p : a) {
        while (!b.empty() and b.back().second >= p.second) b.pop_back();
        b.push_back(p);
    }
    
    int sz = b.size();
    vector<vector<int>> up(sz, vector<int>(18, sz));
    for (int i = 0; i < sz; i++) {
        i64 L = i + 1, R = sz - 1;
        ans = sz;
        while(L <= R) {
            i64 mid = L + R >> 1;
            if (b[mid].first >= b[i].second) { 
                ans = mid; 
                R = mid - 1; 
            } else {
                L = mid + 1;
            }
        }
        up[i][0] = ans;
    }
    
    for (int j = 1; j < 18; j++) {
        for (int i = 0; i < sz; i++) {
            if (up[i][j - 1] < sz) {
                up[i][j] = up[up[i][j - 1]][j - 1];
            }
        }
    }
    
    cin >> m;
    while(m--) {
        int x, y;
        cin >> x >> y;
        int L = 0, R = sz - 1, id1 = sz;
        while(L <= R) {
            int mid = L + R >> 1;
            if (b[mid].first >= x) { 
                id1 = mid; 
                R = mid - 1; 
            } else {
                L = mid + 1;
            }
        }
        
        if (id1 == sz or b[id1].second > y) {
            cout << 0 << "\n";
            continue;
        }
        
        int curr = id1;
        ans = 1;
        for (int j = 17; j >= 0; j--) {
            int nxt = up[curr][j];
            if (nxt < sz and b[nxt].second <= y) {
                curr = nxt;
                ans += (1 << j);
            }
        }
        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
