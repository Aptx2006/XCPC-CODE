#include<bits/stdc++.h>
using namespace std;
#define int long long
#define dbg(A) cout<<#A<<':'<<A<<'\n';
const int N = 2e5+5,M = 1e9+7;
int n,m,ans;
void solve(){
    string tag,s;
    cin >> tag;
    int sizetag=tag.size()-1;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s;
        int len=s.size()-1;
        if(tag[0]!=s[0]&&tag[len]!=tag[sizetag]){
            //cout<<"1NO\n";continue;
        }
        if(s[0]=='R'){
            int l=0,r=sizetag,L=0,R=len;
            for(;l<=r&&L<=R;){
                if(tag[l]==s[L]){
                    L++;l++;
                }else{
                    l++;
                }
            }
            if(L>R){
                cout<<"YES\n";continue;
            }
        }
        if(s[len]=='L'){
            int l=0,r=sizetag,L=0,R=len;
            for(;l<=r&&L<=R;){
                if(tag[r]==s[R]){
                    R--;r--;
                }else{
                    r--;
                }
            }
            if(R<L){
                cout<<"YES\n";continue;
            }
        }
        cout<<"NO\n";
    }
} 
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T = 1; cin >> T;
    while(T--) solve();
    return 0;
}
