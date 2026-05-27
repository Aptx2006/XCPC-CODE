#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T, n, m, k, ans, cnt;

void solve() {
    int n;
    cin>>n;
    vector<i64> a(n+2),b(n+2),dp(n+2);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    i64 sum=0,ans=0;
    for(int i=1;i<=n;i++){
        sum++;
        dp[0]++;
        if(a[i]!=b[i]){
            sum-=dp[a[i]-1];
            dp[a[i]-1]=0;
            sum-=dp[b[i]-1];
            dp[b[i]-1]=0;
        }
        else{
            dp[a[i]]+=dp[a[i]-1];
            dp[a[i]-1]=0;
        }
        ans+=sum;
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
