#include<bits/stdc++.h>
using namespace std;
#define int long long
using ld = long double;
const int N = 2e5+5,M=1e9+7;
int n,m,a[N];
int query(int x,int y){
    cout<<"? "<<x<<" "<<y<<endl;
    int t;cin>>t;
    return t;
}
void solve(){
    cin>>n;
    if(n%2==1){
        int p1,p2,num=0;
        for(int i=1;i+1<n;i+=2){
            int t;
            t=query(i,i+1);num+=t;
            if(t==1){
                p1=i,p2=i+1;
            }
        }
        if(num>=2){
            cout<<"! 1"<<endl;return;
        }
        if(num==0){
            int t=query(n,1);
            if(t==0){
                cout<<"! 1"<<endl;return;
            }else{
                num=query(n,2)+query(n,3);
                if(num==2){
                    cout<<"! 2"<<endl;
                }else{
                    cout<<"! 1"<<endl;
                }
                return;
            }
        }
        if(num==1){
            int pp1=1,pp2=2;
            if(p1==1)pp1=3,pp2=4;
            num=0;
            int t=query(p1,pp1);num+=t;
            if(t==0){
                num=0;
                num=query(p2,pp1)+query(p2,pp2);
                if(num==2){
                    cout<<"! "<<2<<endl;
                }else{
                    cout<<"! "<<1<<endl;
                }
                return;
            }
            num=0;
            t=query(p1,pp2);num+=t;
            if(num==1){
                cout<<"! "<<2<<endl;
            }else{
                cout<<"! "<<1<<endl;
            }
            return;
        }
    }else{
        int num=0;
        int p1=0,p2=0;
        for(int i=1;i<=n;i+=2){
            int t=query(i,i+1);
            num+=t;
            if(t==1){p1=i,p2=i+1;}
        }
        if(num>=2){
            cout<<"! "<<1<<endl;return;
        }else if(num==0){
            cout<<"! "<<1<<endl;return;
        }else{
            int pp1=1,pp2=2;
            if(p1==1)pp1=3,pp2=4;
            num=0;
            int t=query(p1,pp1);num+=t;
            if(t==0){
                num=0;
                num=query(p2,pp1)+query(p2,pp2);
                if(num==2){
                    cout<<"! "<<2<<endl;
                }else{
                    cout<<"! "<<1<<endl;
                }
                return;
            }
            num=0;
            t=query(p1,pp2);num+=t;
            if(num==1){
                cout<<"! "<<2<<endl;
            }else{
                cout<<"! "<<1<<endl;
            }
            return;
        }
    }
}
signed main(){
    int T = 1; cin >> T;
    while(T--) solve();
}