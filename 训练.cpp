#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

i64 T = 1, n, m, k, ans, cnt;
const i64 mod = 998244353;

const int MAX_PRIME = 3162;
vector<int> primes;
vector<bool> is_prime(MAX_PRIME + 1, true);

void precompute() {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= MAX_PRIME; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= MAX_PRIME; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

i64 get_coprime_count(i64 x, const vector<i64>& pf) {
    if (x <= 0) return 0;
    i64 count = 0;
    int k = pf.size();
    for (int mask = 0; mask < (1 << k); mask++) {
        i64 prod = 1;
        int bits = 0;
        for (int i = 0; i < k; i++) {
            if ((mask >> i) & 1) {
                prod *= pf[i];
                bits++;
            }
        }
        if (bits % 2 == 1) {
            count -= x / prod;
        } else {
            count += x / prod;
        }
    }
    return count;
}

void solve() {
    i64 l, r;
    cin >> l >> r >> n;
    
    vector<i64> pf;
    i64 temp = n;
    for (int p : primes) {
        if ((i64)p * p > temp) break;
        if (temp % p == 0) {
            pf.push_back(p);
            while (temp % p == 0) temp /= p;
        }
    }
    if (temp > 1) {
        pf.push_back(temp);
    }
    
    i64 coprime_in_range = get_coprime_count(r, pf) - get_coprime_count(l - 1, pf);
    i64 total_numbers = r - l + 1;
    
    i64 total_cost = coprime_in_range * 1 + (total_numbers - coprime_in_range) * 2;
    
    cout << total_cost << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    precompute(); 
    for(cin >> T; T--; solve());
    return 0;
}
