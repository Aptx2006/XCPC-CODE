#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    int ans = *max_element(a.begin(), a.end()) -  *min_element(a.begin(), a.end()); 
    cout << "1 " << n << ' ' << ans << '\n';
}