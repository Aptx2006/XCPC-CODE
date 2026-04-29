#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T, n, m, k;
i64 ans, cnt;

void solve() {
	cin >> n;
	auto ins = [](i64 x){
		cout << "I " << x << endl;
		int res;
		cin >> res;
		if(res == -1) exit(0);
		return res;
	};
	auto ask = [](i64 x){
		cout << "Q " << x << endl;
		int res;
		cin >> res;
		if(res == -1) exit(0);
		return res;
	};
	auto print = [](int k, i64 c) {
		cout << "A " << k << " " << c << endl;
	};

	cout << 0 << endl;
	int s1 = ins(0);
	if(s1 == 1) { // k =
		i64 a = (1LL << n) - 1;
		ins(a);
		i64 l = 1, r = (1LL << n) - 1, c = 1;
        ans = 1;
		while(l <= r) {
			i64 mid = (l + r) >> 1;
			int q = ask(mid);
			if(q >= 1) ans = mid, l = mid + 1;
			else r = mid - 1;
		}
		print(1, ans);
	}else {
        i64 l = 1, r = (1LL << n) - 1, c = 1;
        ans = 1;
        while(l <= r) {
            i64 mid = (l + r) >> 1;
            int q = ask(mid);
            if(q >= 1) ans = mid, l = mid + 1;
            else r = mid - 1;
        }
        if(ans != 1 and ans & 1) {
            i64 x = ans & -ans;
            int s2 = ins(x);
            if(s2 == 2) print(2, ans);
            else print(3, ans);
        } else {
            if((ans & -ans) != ans){
                i64 x = ans & -ans;
                int s2 = ins(x);
                if(s2 == 2) print(2, ans);
                else print(3, ans);
            }else{
                i64 x = (ans == 1) ? 2 : 1;
                ins(x);
                int s3 = ins(ans + x);
                if(s3 == 3) print(2, ans);
                else print(3, ans);
            }
        }
    }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> T;
	while(T--) solve();
	return 0;
}
