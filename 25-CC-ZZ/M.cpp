#include<bits/stdc++.h>
using namespace std;
#define ing long long
#define all(A) A.begin(),A.end()
const int N = 5e5+5,M=1e9+7;
int n,m;
bitset<N>b[3];
string s;
void solve(){
    auto work = [](string s){
        string res = "";
        bool f = 0;
        for(auto &x:s){
            if(x=='1') f = 1;
            if(f) res += x;
        }
        if(res.size()==0) res+='0';
        return res;
    };
    auto get = [&](int id1,string &ans){
        for(int i=0;i<id1;i++){
            int id = id1-1-i;
            if(s[i]=='1') b[1].set(id);
        }
        for(int i=id1+1;i<n;i++){
            int id = n-1-i;
            if(s[i]=='1') b[2].set(id);
        }
        //cout << s << ' ' << b[1].to_ulong() << ' ' << b[2].to_ulong() << endl;
        for(int i=0;i<n;i++){
            if(b[1][i]!=b[2][i]) ans[n-1-i] = '1';
            b[1].reset(i),b[2].reset(i);
        }
    };

    cin >> s;
    n = s.size();
    string s1(n,'0'),s2 = s1,s3 = s1,s4 = s1;
    get(1,s1), get(n-2,s2);
    //3
    int id1 = -1,id2 = -1,flag = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='1') flag = 1;
        else if(flag){
            id1=i;break;
        }
    }
    flag = 0;
    for(int i=n-1;i>=0;i--){
        if(s[i]=='1') flag = 1;
        else if(flag){
            id2=i;break;
        }
    }
    if(id1!=-1 and id1!=n-1 and id1!=1 and id1!=n-2)  get(id1,s3);
    if(id2!=-1 and id2!=0 and id2!=1 and id2!=n-2)  get(id2,s4);
    string ans = max({s1,s2,s3,s4});
    cout << work(ans) << "\n";
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T = 1; cin >> T;
    while(T--) solve();
}