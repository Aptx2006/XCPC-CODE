#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
#define all(A) A.begin(), A.end()
#define dbg(A) cerr << (#A) << ':' << (A) << endl;

const int N = 6e4 + 5;
using U = unsigned i64;
const U mod1 = 1e9 + 7, base1 = 127;
const U mod2 = 1e9 + 9, base2 = 131;
vector<U> val1, val2;

void init(int n = N) {
    val1.resize(n + 1), val2.resize(n + 1);
    val1[0] = val2[0] = 1;
    for(int i = 1; i <= n; i++) {
        val1[i] = val1[i - 1] * base1;
        val2[i] = val2[i - 1] * base2;
    }
}

struct String {
    vector<U> hash1, hash2;
    string s;
    String(string s_): s(s_), hash1{1}, hash2{1}{
        for(auto it:s){
            hash1.push_back(hash1.back()*base1+it);
            hash2.push_back(hash2.back()*base2+it);
        }
    }
    pair<U,U> get(){
        return {hash1.back(),hash2.back()};
    }
    pair<U,U> substring(int l,int r){
        if(l>r)swap(l,r);
        U ans1=hash1[r+1]-hash1[l]*val1[r-l+1];
        U ans2=hash2[r+1]-hash2[l]*val2[r-l+1];
        return {ans1,ans2};
    }
    
};

void solve() {
    int n, q, m, k;
    cin >> n >> q >> m >> k;
    vector<String> a;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        a.push_back(String(s));
    }
    while(q--) {
        string s;
        cin >> s;
        String cur(s);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int cnt = 0, j = 0;
            while(cnt < k and j < m) {
                int l = j + 1, r = m;
                int res = j;
                while(l <= r) {
                    int mid = l + r >> 1;
                    if(cur.substring(j, mid - 1) == a[i].substring(j, mid - 1)) {
                        l = mid + 1;
                        res = mid;
                    } else {
                        r = mid - 1;
                    }
                }
                j = res + 1;
                cnt++;
            }
            if(j >= m or cur.substring(j, m - 1) == a[i].substring(j, m - 1)) {
                ans++;
            }
        }
        cout << ans << '\n';
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int T = 1;
    //cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}