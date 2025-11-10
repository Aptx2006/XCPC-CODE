#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+5, MOD = 1e9+7;
int n, m,ans,H, W;
int h[3], w[3];
void A1() {
    ans = 1;
    for(int i=0;i<3;i++){
        if(h[i]*w[i]!=n*m){
            ans = (ans * (n - h[i] + 1) %MOD * (m - w[i] + 1) % MOD)%MOD;
        }
    }
    cout<<ans<<'\n';
}
void A2() {
    if (W == 3) {
        swap(n, m),swap(h[0], w[0]),swap(h[1], w[1]),swap(h[2], w[2]);
    }
    ans = 0;
    if (w[0] + w[1] + w[2] < m) {
        cout << "0\n";return;
    }
    if (w[0] + max(w[1], w[2]) >= m) ans += 2;
    if (w[1] + max(w[0], w[2]) >= m) ans += 2;
    if (w[2] + max(w[0], w[1]) >= m) ans += 2;
    if (w[0] + w[1] >= m) ans = (ans + 2 * (m - w[2] - 1))%MOD;
    else {
        int L = max(2LL, m - w[1] - w[2] + 1),R = min(m - w[2], w[0] + 1);
        if (L <= R) ans =  (ans + 2 * (R - L + 1))%MOD;
    }
    if (w[0] + w[2] >= m) ans = (ans + 2 * (m - w[1] - 1))%MOD;
    else {
        int L = max(2LL, m - w[2] - w[1] + 1),R = min(m - w[1], w[0] + 1);
        if (L <= R) ans = (ans + 2 * (R - L + 1))%MOD;
    }
    if (w[1] + w[2] >= m) ans = (ans + 2 * (m - w[0] - 1))%MOD;
    else {
        int L = max(2LL, m - w[2] - w[0] + 1),R = min(m - w[0], w[1] + 1);
        if (L <= R) ans = (ans + 2 * (R - L + 1))%MOD;
    }
    cout << ans << "\n";
}

void A3() {
    if (W == 2) {
        swap(n, m),swap(h[0], w[0]),swap(h[1], w[1]),swap(h[2], w[2]);
    }
    int A, B;
    for(int i=0;i<3;i++){
        if(h[i]!=n){
            if(i==2) A = w[0],B = w[1];
            else if(i==1) A = w[0],B = w[2];
            else A = w[1],B = w[2];
            if(A+B<m) cout<<"0\n";
            else cout << 2 * (n - h[i] + 1) % MOD * (m - w[i] + 1) % MOD << "\n";
            return;
        }
    }
}

void A4() {
    int sumh = 0,sumw = 0;
    for(int i=0;i<3;i++) sumh+=h[i],sumw+=w[i];
    if (sumh >= 2 * n and sumw >= 2 * m)  cout << "4\n";
    else  cout << "0\n";
}
void A5() {
    if (W == 1) 
        swap(n, m),swap(h[0], w[0]),swap(h[1], w[1]),swap(h[2], w[2]);
    for(int i=1;i<3;i++) 
        if(h[i]==n) swap(h[0],h[i]),swap(w[0],w[i]);
    for(int i=1;i<3;i++)
        if (w[0] + w[i] < m) {
            cout << "0\n";return;
        }
    if (h[1] + h[2] < n) {
        cout << "0\n";return;
    }
    cout << "4\n";
}
void solve(){
    cin >> n >> m ;
    for(int i=0;i<3;i++) cin >> h[i] >> w[i];
    for(int i=0;i<3;i++)
        if (h[i] * w[i] == n * m) {
            A1();return;
        }
    H = W = 0;
    for(int i=0;i<3;i++) 
        H += h[i]==n,W += w[i]==m;
    if (H + W==0)  cout << "0\n";
    else if (H == 3 or W == 3)   A2();
    else if (H == 2 or W == 2)   A3();
    else if (H == 1 and W == 1)   A4();
    else if (H + W == 1) A5();
}
signed main() { 
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int times;cin >> times;
    while(times--) solve();
    return 0;
}
