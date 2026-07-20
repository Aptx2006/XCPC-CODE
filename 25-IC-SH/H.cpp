#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
#define all(A) (A).begin(), (A).end()

int T = 1, n, m;

void solve() {
    cin >> n;
    vector<i64> a(2 * n), b;
    for(auto &x: a) cin >> x;
    int res=0,num=0;
    map<int,int>mp;
    for(int x:a)mp[x]++;
    auto get = [&](int num) {
        return num / 2 % 2 == 1;
    };
    for(auto[x,y]:mp){
        if(y%2==1){
            num++;
            b.push_back(x);
            res^=get(y-1) * x; 
        }
        if(y%2==0&&get(y))res^=x;
    }
    if(b.empty()){
        cout<<(res==0?"Menji\n":"Bot\n");return;
    }
    if(num > 2){
        cout<<"Bot\n";return;
    }
    for(auto &x: b) {
        if(x == res) {
            cout << "Menji\n";
            return;
        }
    }
    cout<<"Bot\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}