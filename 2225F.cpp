#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;

const u64 base = 131, mod1 = 212370440130137957ULL;

vector<u64> pres, powb;

void init(const string &s) {
    int n = s.size();
    powb.assign(n + 1, 1);
    for (int i = 0; i < n; i++) {
        powb[i + 1] = ((u128)powb[i] * base) % mod1;
    }
    pres.assign(n + 1, 0);
    for (int i = 0; i < n; i++) {
        pres[i + 1] = ((u128)pres[i] * base + s[i]) % mod1;
    }
}

u64 get_sub_s(int l, int r) {
    return (pres[r + 1] - (u128)pres[l] * powb[r - l + 1] % mod1 + mod1) % mod1;
}

int get_lcp(int l1, int r1, int l2, int r2) {
    int len1 = r1 - l1 + 1, len2 = r2 - l2 + 1;
    int l = 1, r = min(len1, len2), ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (get_sub_s(l1, l1 + mid - 1) == get_sub_s(l2, l2 + mid - 1)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return ans;
}

int cmp_sub(int l1, int r1, int l2, int r2, const string &s) {
    int len1 = r1 - l1 + 1, len2 = r2 - l2 + 1;
    int lcp = get_lcp(l1, r1, l2, r2);
    if (lcp == len1 && lcp == len2) return 0;
    if (lcp == len1) return -1;
    if (lcp == len2) return 1;
    return s[l1 + lcp] < s[l2 + lcp] ? -1 : 1;
}

int n, m, k, l, T;
string s;

void solve() {
    cin >> n >> l >> k;
    cin >> s;
    if(1LL * k * l > n) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    if(k == 1) {
        cout << s << "\n";
        return;
    }
    
    init(s);
    
    int ansL = -1, ansR = -1;
    for(int i = 0; i < n; i++) {
        int left = i;
        int right = -1;
        if(i == 0) {
            int d = (k - 1) * l;
            right = n - d - 1;
        }else {
            if(i >= l) {
                int d1 = i / l;
                if(d1 >= k - 1) {
                    if (n - i >= l) {
                        right = n - 1;
                    }
                }else {
                    int nd = k - 1 - d1;
                    int kl = nd * l;
                    right = n - kl - 1;
                }
            }
        }
        
        if(right != -1 and right - left + 1 >= l) {
            if(ansL == -1) {
                ansL = left;
                ansR = right;
            }else {
                if (cmp_sub(left, right, ansL, ansR, s) > 0) {
                    ansL = left;
                    ansR = right;
                }
            }
        }
    }
    
    cout << s.substr(ansL, ansR - ansL + 1) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
