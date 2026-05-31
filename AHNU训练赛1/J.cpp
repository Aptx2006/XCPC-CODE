#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define all(A) A.begin(),A.end()
#define point pair<int,int>
#define x first
#define y second
const int mod=1e9+7,N=2e5+8;
int n,m,k,a[N];
string atos(vector<int>a){
    string s;
    for(int i=0;i<9;i++){
        s+=a[i]+'0';
    }
    return s;
}
vector<int> right(vector<int>a,int r){
    vector<int>b=a;
    if(r==1){
        b[0]=a[2];
        b[1]=a[0];
        b[2]=a[1];
    }
    if(r==2){
        b[3]=a[5];
        b[4]=a[3];
        b[5]=a[4];
    }
    if(r==3){
        b[6]=a[8];
        b[7]=a[6];
        b[8]=a[7];
    }
    return b;
}
vector<int> down(vector<int>a,int r){
    vector<int>b=a;
    b[0+r-1]=a[6+r-1];
    b[3+r-1]=a[0+r-1];
    b[6+r-1]=a[3+r-1];
    return b;
}
vector<int>spin(vector<int>a){
    vector<int>b=a;
    b[2]=a[0];
    b[5]=a[1];
    b[8]=a[2];
    b[1]=a[3];
    b[4]=a[4];
    b[7]=a[5];
    b[0]=a[6];
    b[3]=a[7];
    b[6]=a[8];
    return b;
}
unordered_map<string,int>mp1,mp2;
void init(vector<int>a){
    queue<vector<int>>Q;
    Q.push(a);mp1[atos(a)]=0;
    int cnt=0;
    while(!Q.empty()){
        auto x=Q.front();Q.pop();
        for(int i=1;i<=3;i++){
            auto b=right(x,i);
            if(!mp1.count(atos(b))){
                mp1[atos(b)]=mp1[atos(x)]+1;
                Q.push(b);
            }
            b=down(x,i);
            if(!mp1.count(atos(b))){
                mp1[atos(b)]=mp1[atos(x)]+1;
                Q.push(b);
            }
        }
        auto b=spin(x);
        if(!mp1.count(atos(b))){
            mp1[atos(b)]=mp1[atos(x)]+1;
            Q.push(b);
        }
    }
}
void init2(vector<int>a){
    queue<vector<int>>Q;
    Q.push(a);mp2[atos(a)]=0;
    int cnt=0;
    while(!Q.empty()){
        auto x=Q.front();Q.pop();
        for(int i=1;i<=3;i++){
            auto b=right(x,i);
            if(!mp2.count(atos(b))){
                mp2[atos(b)]=mp2[atos(x)]+1;
                Q.push(b);
            }
            b=down(x,i);
            if(!mp2.count(atos(b))){
                mp2[atos(b)]=mp2[atos(x)]+1;
                Q.push(b);
            }
        }
        auto b=spin(x);
        if(!mp2.count(atos(b))){
            mp2[atos(b)]=mp2[atos(x)]+1;
            Q.push(b);
        }
    }
}
void solve(){
    vector<int>a(9,0),b(9,0);
    string s1,s2;
    for(int i=1;i<=3;i++){
        string t;cin>>t;
        s1+=t;
    }
    for(int i=1;i<=3;i++){
        string t;cin>>t;
        s2+=t;
    }
    for(int i=0;i<9;i++){
        a[i]=s1[i]-'0';
        b[i]=s2[i]-'0';
    }
    map<int,int>mp;
    for(int i=0;i<9;i++){
        mp[a[i]]=i+1;
    }
    vector<int>c2(9);
    for(int i=0;i<9;i++){
        c2[i]=mp[b[i]];
    }
    //for(int i=0;i<9;i++)cout<<c2[i]<<' ';
    if(mp1.count(atos(a))&&mp1.count(atos(b))){
        cout<<mp1[atos(c2)]<<"\n";
    }else if(mp2.count(atos(a))&&mp2.count(atos(b))){
        cout<<mp1[atos(c2)]<<"\n";
    }else{
        cout<<"-1\n";
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    vector<int>a(9);
    for(int i=0;i<9;i++)a[i]=i+1;
    init(a);
    swap(a[0],a[1]);
    init2(a);
    int t=1;cin>>t;
    while(t--)
    solve();
    return 0;
}