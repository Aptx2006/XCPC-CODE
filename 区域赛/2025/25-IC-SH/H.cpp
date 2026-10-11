#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

#define dbg(A) cout << (#A) << ':' <<  (A) << endl;

const int N = 20;
int n, m;
i64 pw3[N];

void init() {
    
}

struct LB { // Linear Basis
    using i64 = long long;
    const int BASE = 63;
    vector<i64> d, p;
    int cnt, flag;

    LB() {
        d.resize(BASE + 1);
        p.resize(BASE + 1);
        cnt = flag = 0;
    }
    bool insert(i64 val) {
        for (int i = BASE - 1; i >= 0; i--) {
            if (val & (1ll << i)) {
                if (!d[i]) {
                    d[i] = val;
                    return true;
                }
                val ^= d[i];
            }
        }
        flag = 1; //可以异或出0
        return false;
    }
    bool check(i64 val) { // 判断 val 是否能被异或得到
        for (int i = BASE - 1; i >= 0; i--) {
            if (val & (1ll << i)) {
                if (!d[i]) {
                    return false;
                }
                val ^= d[i];
            }
        }
        return true;
    }
    i64 ask_max() {
        i64 res = 0;
        for (int i = BASE - 1; i >= 0; i--) {
            if ((res ^ d[i]) > res) res ^= d[i];
        }
        return res;
    }
};

void solve() {
    cin >> n;
    vector<int>a(n*2);
    map<int,int>mp;
    for(int i=0;i<n*2;i++){
        cin>>a[i];
        mp[a[i]]++;
    }
    int res=0;
    set<int>s;
    for(auto[x,y]:mp){
        if(y&1)s.insert(x);
        if(y/2%2==1)res^=x;
    }
    if(s.size()>2){
        cout<<"Bot\n";return;
    }
    if(res==0 and s.size()==0){
        cout<<"Menji\n";return;
    }
    cout<<(s.count(res)?"Menji\n":"Bot\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int T = 1;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}
