#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
#define all(x) (x).begin(), (x).end()

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), lis;
	for(int &x : a) cin >> x;
	for(int x : a) {
		auto it = lower_bound(all(lis), x);
		if (it == lis.end()) lis.push_back(x);
		else *it = x;
	}
	cout << lis.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
