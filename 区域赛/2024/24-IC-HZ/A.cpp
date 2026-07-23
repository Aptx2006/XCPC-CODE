#include<bits/stdc++.h>
using namespace std;
#define int long long
int fa[30];
int root(int x){
    return fa[x] = fa[x] == x?x:root(fa[x]);
}
void merg(int x,int y){
    x=root(x),y=root(y);
    if(x!=y) fa[x] = fa[y];
}
void solve(){
    string s1,s2,s3;
    cin >> s1 >> s2 >> s3;
    if(s1.size()!=s2.size()){
        cout<<"NO\n";
        return;
    }
    if(s1.size()!=s3.size()){
        cout<<"YES\n";
        return;
    }
    for(int i=0;i<30;i++) fa[i] = i;
    int n = s1.size();
    for(int i=0;i<n;i++){
        merg(s1[i]-'a',s2[i]-'a');
    }
    for(int i=0;i<n;i++){
        if(root(s3[i]-'a')!=root(s1[i]-'a')) {
            cout<<"YES\n";return;
        }
    }
    cout<<"NO\n";
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int times;cin >> times;
    while(times--) solve();
    return 0;
}
