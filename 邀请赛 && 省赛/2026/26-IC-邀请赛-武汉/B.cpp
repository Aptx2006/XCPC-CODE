#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

using P = pair<i64, i64>;
i64 n, m, q, ans;

void solve() {
    int n,m;cin>>n>>m;
    vector<int>a(n),x(m),c(m);
    set<int>s;
    auto mex=[](int a,int b){
        if(a>b)swap(a,b);
        if(a!=0)return 0;
        if(b==1)return 2;
        return 1;
    };
    for(int i=0;i<n;i++){
        cin>>a[i];
        s.insert(a[i]);
    }
    for(int i=0;i<m;i++){
        cin>>c[i]>>x[i];
    }
    for(int i=1;i<m;i++){
        if(c[i]==1 and c[i-1]==2){
            cout<<"Yes\n";return;
        }
        if(c[i]==1 and c[i-1]==0){
            cout<<"Yes\n";return;
        }
        if(c[i]==0 and c[i-1]==2){
            cout<<"Yes\n";return;
        }
        if(c[i]==0 and c[i-1]==0){
            cout<<"Yes\n";return;
        }
    }

    for(int i=1;i+1<m;i++){
        if(c[i-1]==c[i+1] and c[i]==0){
            c[i]=c[i-1];
        }
    }
    int id=-1;
    for(int i=0;i<m;i++){
        if(c[i]==0){
            id=i;break;
        }
    }
    if(id==-1){
        for(int i=0;i<m;i++){
            set<int>ss;
            for(int num:s){
                if(c[i]==1){
                    ss.insert(mex(x[i],num));
                }else{
                    ss.insert(__gcd(x[i],num));
                }
            }
            s=ss;
        }
        cout<<(s.size()==1?"Yes\n":"No\n");
    }else{
        c[id]=1;
        for(int i=0;i<m;i++){
            set<int>ss;
            for(int num:s){
                if(c[i]==1){
                    ss.insert(mex(x[i],num));
                }else{
                    ss.insert(__gcd(x[i],num));
                }
            }
            s=ss;
        }
        if(s.size()==1){
            cout<<"Yes\n";return;
        }

        c[id]=2;
        s.clear();
        for(int i=0;i<n;i++){
            s.insert(a[i]);
        }
        for(int i=0;i<m;i++){
            set<int>ss;
            for(int num:s){
                if(c[i]==1){
                    ss.insert(mex(x[i],num));
                }else{
                    ss.insert(__gcd(x[i],num));
                }
            }
            s=ss;
        }
        if(s.size()==1){
            cout<<"Yes\n";return;
        }
        cout<<"No\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}
