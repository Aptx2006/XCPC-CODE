#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T, n, m, k, ans, cnt;

void solve() {
    int a, b;
    cin >> a >> b;
    if(a > b) swap(a, b);
	if(a != 1){
		cout << "1\n";
	} else if(a * 2 < b) {
		cout << a * 2 <<'\n';
	} else {
		cout << a + b <<'\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
