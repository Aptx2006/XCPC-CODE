#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+5,M = 1e9+7;
#define double long double
const double eps = 1e-13;
int n,m;
double a[N];
int sgn(double x) {	
    return x < -eps ? -1 : x > eps; 
}
bool check(double c){
    double sum=0;
    for(int i=1;i<=n;i++){
        sum += (c*a[i]*1.0)/(1.0+c*a[i]);
    }
    //<<c<<' '<<sum<<'\n';
    return sum > m;
}
void solve(){
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    double L = -1e13,R = 1e13;
    double ans=1.0;
    while(sgn(R-L)){
        double mid = (L+R)/2.0;
        if(check(mid)){
            ans = mid;R = mid;
        }else{
            L = mid;
        }
    }
    //cout<<ans<<'\n';
    for(int i=1;i<=n;i++){
        double p = ((a[i]*ans)*1.0)/(1.0*(1+ans*a[i]));
        cout<<fixed<<setprecision(12)<<p<<'\n';
    }
    return;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    //int times;cin >> times;while(times--) 
    solve();
    return 0;
}
