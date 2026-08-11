#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;

void solve() {
    int n,w;cin>>n>>w;
    string s;cin>>s;
    bool f=0;
    for(char ch:s){
        if(ch=='^'){
            f=1;break;
        }
    }
    cout<<"Yes\n";
    if(!f){
        for(int i=0;i<n;i++)cout<<w<<' ';
        cout<<'\n';return;
    }else{
        cout<<w<<' ';
        f=0;
        for(char ch:s){
            if(ch=='^'){
                f=1;
            }
            if(f)cout<<0<<' ';
            else cout<<w<<' ';
        }
        cout<<'\n';
        return;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
