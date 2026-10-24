#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;
#define all(A) A.begin(), A.end()
#define dbg(A) cerr << (#A) << ':' << (A) << endl;

i128 qpow(i128 a,i128 b){
    i128 res = 1;
    while(b){
        if(b&1){
            res*=a;
        }
        b>>=1;
        a=a*a;
    }
    return res;
}

void solve(){
    i64 n, k, ans = 0;
    cin >> n >> k;
    i128 N = n;
    if(k > 3) {
        set<i128> st;
		for(int i = 1; qpow(i, k) - qpow(i - 1, k) <= n; i++){
			i128 r = qpow(i, k);
			if(r >= n and st.count(r - n)) ans++;
			st.insert(r);
		}
    }else {
        // x * (3*b^2 + 3*b*x + x^2)
        for(i128 x = 1; x * x * x <= N; x++) {
            if(N % x != 0) continue;
            auto fun = [&](i128 b) -> i128 {
                return 3 * b * b + 3 * b * x + x * x;
            };
            i128 l = 1, r = 8e8, b = l;
            while(l <= r) {
                i128 mid = l + r >> 1;
                i128 f = fun(mid);
                if(x * f < N) {
                    l = mid + 1;
                }else if(x * f > N){
                    r = mid - 1; 
                }else {
                    ans++;
                    break;
                }
            }
        }
    }
    cout << ans << '\n';
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}