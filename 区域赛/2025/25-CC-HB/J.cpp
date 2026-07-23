#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+5,M=1e9+7;
#define all(A) A.begin(),A.end()
#define dbg(A) cout<<#A<<":"<<A<<' ';
int n,m,a[N];string s;
pair<vector<int>,vector<int>> Manacher(string s){
    int n = s.size();
    vector<int>d1(n),d2(n);
    for(int i=0,l=0,r=-1;i<n;i++){
        int k = (i>r)?1:min(d1[l+r-i],r-i+1);
        while(0<=i-k and i+k<n and s[i-k]==s[i+k]) k++;
        d1[i] = k--;
        if(i+k>r){
            l=i-k;r=i+k;
        }
    }
    for(int i=0,l=0,r=-1;i<n;i++){
        int k = (i>r)?0:min(d2[l+r-i+1],r-i+1);
        while(0<=i-k-1 and i+k<n and s[i-k-1]==s[i+k]) k++;
        d2[i] = k--;
        if(i+k>r){
            l=i-k-1;r=i+k;
        }
    }
    return{d1,d2};
}
void solve(){
    cin >> n >> s;
    string s2;
    vector<int>c1(2*n+1),c2(2*n+1),c3(2*n+1);
    for(auto x:s){
        if(x=='w'){
            c2[s2.size()]=1;
            s2+="vv";
        }
        else {
            c2[s2.size()]=1;
            s2+=x;
        }
    }
    for(int i=1;i<=2*n;i++){
        c3[i]=c2[i-1]+c3[i-1];
    }
    auto [d1,d2]=Manacher(s2);
    
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T = 1; cin >> T;
    while(T--) solve();
}