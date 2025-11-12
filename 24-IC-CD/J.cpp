#include<bits/stdc++.h>
using namespace std;
#define int long long
using ld = long double;
#define dbg(A) cout<<#A<<" : "<<A<<endl;
#define all(A) A.begin(), A.end()
const int N = 1e5+5,M = 1e9+7;
int n,m,q,ans;
struct player{
    int score;
    unordered_set<int>info;
};
void solve(){
    cin >> n >> m >> q;
    vector<int>level(n+1,0);
    vector<player>a(m+1);
    int cur = 0;
    while(q--){
        int op,id,x;
        cin >> op;
        if(op==1){
            cin >> x;
            level[x] = (!level[x]?1:0);
            cur = x;
        }else{
            cin >> id >> x;
            if(x==cur and level[x]){
                if(!a[id].info.count(x)){
                    a[id].info.insert(x);
                    if(op==2)
                        a[id].score+=(m-level[x]+1),level[x]++;
                }
            }
        }
    }
    vector<int>id(m);
    for(int i=0;i<m;i++) id[i] = i+1;
    sort(all(id),[&](auto o1,auto o2){
        if(a[o1].score!=a[o2].score)
            return a[o1].score>a[o2].score;
        return o1<o2;
    });
    for(auto x:id){
        cout<<x<<' '<<a[x].score<<'\n';
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T = 1; cin >> T;
    while(T--) solve();
}