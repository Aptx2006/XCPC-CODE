#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

i64 T = 1, n, m, k, ans, cnt;

void solve() {
    cin >> n;

    vector<i64> a;
    multiset< pair<i64, i64> > s;
    multiset< pair<i64, i64> > s_;
    i64 ans = 0, sum = 0, cnt = 0;

    auto work = [&] {
        reverse(all(a));
        int sz = a.size();

        while((int)s.size() < cnt) {
            if(s_.empty()) break;
            auto it = prev(s_.end());
            s.insert(*it);
            sum += it->first;
            s_.erase(it);
        }

        for(int i = 0; i < sz; i++) {
            i64 val = a[i] * (i + 1);
            s.insert({val / (sz + 1),  val % (sz + 1)});
            ans += val;
        }
        ans += sum * (sz + 1);
        
        int del = (int)s.size() - cnt;
        auto it = s.begin();
        while(del-- > 0) {
            ans -= it->first * (sz + 1) + it->second;
            it++;
        }

        for(int i = 0; i < sz; i++) {
            i64 val = a[i] * (i + 1);
            s.extract({val / (sz + 1), val % (sz + 1)});
            s.insert({a[i], 0});
            sum += a[i];
        }

        while((int)s.size() > cnt) {
            auto it = s.begin();
            sum -= it->first;
            s_.insert(*it);
            s.erase(it);
        }

        a.clear();
    };

    while(n--) {
        char c;
        cin >> c;
        if(c == 'W') {
            work();
            cnt++;
        }else {
            cin >> k;
            a.push_back(k);
        }
    }

    work();
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
}
