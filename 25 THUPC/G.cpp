#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize(2)
/*i32 : -2e9~2e9
i64: -9e18~9e18
u64: 0~1.8e19*/
using i64 = long long;
using u64 = unsigned long long;
#define dbg(A) cout << #A << "==" << A << '\n';
#define all(A) A.begin(), A.end()
#define int long long

const int MAXN = 1E5 + 5, MOD = 1E9 + 7, INF = 1E18;

int n, m, t, ar[MAXN], ans, cnt, k;
vector<int> qiuhe(vector<int>t1,vector<int>t2,int n){
    int c=0;
    vector<int>ans(n+1,0);
    for(int i=0;i<n;i++){
        int jieguo=c+t1[i]+t2[i];
        if(jieguo==0){
            ans[i]=0;
            c=0;
        }
        else if(jieguo==1){
            ans[i]=1;
            c=0;
        }
        else if(jieguo==2){
            ans[i]=0;
            c=1;
        }
        else{
            ans[i]=1;
            c=1;
        }
    }
    return ans;
}
vector<int> qiushu(string s,int p){
    vector<int>a(s.size(),0);
    vector<int>b(s.size(),0);
    int k=0;
    for(int i=p-1;i>=0;i--){
        a[k++]=s[i]-'0';
    }
    k=0;
    for(int i=s.size()-1;i>=p;i--){
        b[k++]=s[i]-'0';
    }
    vector<int>ans=qiuhe(a,b,s.size());
    return ans;
}
vector<int> compare(vector<vector<int>>G){
    vector<int>flag(G.size(),1);
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<G.size();j++){
            if(flag[j]==0)continue;
            for(int k=0;k<G.size();k++){
                if(flag[k]==0||j==k)continue;
                if(G[j][i]>G[k][i]){
                    flag[j]=0;
                    break;
                }
            }
        }
    }
    for(int i=0;i<G.size();i++){
        if(flag[i]==1)return G[i];
    }
    return G[0];
}
void solve() { 
    cin >> n;
    string s;
    cin >> s;
    int a = s.find('1'), b = 0;
    if(a == string::npos) {
        cout << "0\n";
        return;
    }
    a=n-a;
    vector<int>pos;//i is the b
    int count = 0;
    for(int i=n-1;i>=0;i--){
        count++;
        if(s[i] == '1'){
            b += count;
            count = 0;
        }
        a--; 
        if(llabs(a-b) <= 3){
            pos.push_back(i);
        }
        if(a<0)break;
    }
    vector<vector<int>>G(pos.size());
    for(int i = 0 ; i < pos.size() ; i++){
        G[i] = qiushu(s,pos[i]);
    }
    vector<int>ans = compare(G);
    int flag=0;
    for(int i=n;i>=0;i--){
        if(ans[i]==1)flag=1;
        if(flag)cout<<ans[i];
    }
    cout<<"\n";
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int times = 1; cin >> times;
    while (times--) solve();
    return 0;
}
