#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
#define all(A) A.begin(), A.end()

int n, m, k;

void A() {
    cin >> n;
    string p, ans = "";
    cin >> p;
    char tag;
    int cnt = count(all(p), '1'), st = 0;
    if(cnt > n / 2) tag = '1', st = 1;
    else tag = '0', st = 0;
    // st 表示编码串的第一个字符，同时也表示解码串的主导字符
    for(auto &c: p) {
        if(c == tag) {
            if(st) {
                ans += "1";
            }else {
                ans += "0";
            }
            st = 1 - st;
        }else {
            if(st) {
                ans += "11";
            }else {
                ans += "00";
            }
            st = 1 - st;
        }
    }
    cout << ans.size() << endl;
    cout << ans << endl;
}

void B() {
    cin >> n;
    string q;
    cin >> q;
    char a, b;
    if(q[0] == '0') a = '1', b = '0';
    else a = '0', b = '1';
    string ans = "";
    for(int i = 0; i < n; i++) {
        if(i < n - 1 and q[i] == q[i + 1]) {
            ans += a;
            i++;
        }else {
            ans += b;
        }
    }
    cout << ans.size() << endl;
    cout << ans << endl;
}

void solve(int r){
    if(r == 1) A();
    else B();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1, r;
    cin >> T >> r;
    while(T--) {
        solve(r);
    }
    return 0;
}
