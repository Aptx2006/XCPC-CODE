#include<bits/stdc++.h>
using namespace std;
#define int long long
#define dbg(A) cout<<#A<<':'<<A<<' ';
const int N = 2e5+5,M=1e9+7;
int n,m,k,ans,u,v,w;
void solve(){
    cin >> n >> m >> k >> w;
    vector<int>a(n),b(m),res;
    for(auto &x:a) cin >> x;
    for(auto &x:b) cin >> x;
    b.push_back(0);b.push_back(w+1);
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int pa = 0;
    for(int i=0;i<=m;i++){
        int L = b[i],R = b[i+1];
        vector<int>c,l,r;
        while(a[pa]<R and pa<n)  c.push_back(a[pa++]);
        if(c.empty()) continue;
        //for(auto x:c) cout<<x<<' ';cout<<"\n++++\n";
        l.push_back(c[0]);r.push_back(c[0]+k-1);
        int mx = c[0] - L - 1;//可移动的冗余
        for(int j=1;j<c.size();j++){
            if(c[j]<=r.back()) continue;
            if(r.back()<R)
            mx += c[j] - r.back() - 1;
            l.push_back(c[j]),r.push_back(c[j]+k-1);
        }
        //for(auto x:l) dbg(x);cout<<endl;for(auto x:r) dbg(x);cout<<endl;
        //dbg(mx)
        if(r.back()>=R){
            if(r.back()-R+1>mx){
                cout<<"-1\n";return;
            }
            res.push_back(R-k);
            l[l.size()-1] = R-k,r[l.size()-1] = R-1;
            for(int j=l.size()-2;j>=0;j--){
                if(r[j]>=l[j+1]){
                    int d = r[j] - l[j+1] + 1;
                    l[j] -= d,r[j] -= d;
                    if(l[j]<=L){
                        cout<<"-1\n";return;
                    }
                }
                res.push_back(l[j]);
            }
            continue;
        }
        for(auto x:l) res.push_back(x);
    }
    sort(res.begin(),res.end());
    cout<<res.size()<<'\n';
    for(auto x:res) cout<<x<<' ';
    cout<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T = 1; cin >> T;
    while(T--) solve();
    return 0;
}
