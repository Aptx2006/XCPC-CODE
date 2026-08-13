#include <bits/stdc++.h>
using namespace std;
#define int long long

const int EMPTY = 0;
const int ONE_EDGE = 1;
const int STAR = 2;
const int TRIANGLE = 3;

const int MAXA = 1000005;
int spf[MAXA];
int cnt[MAXA];
int sum_idx[MAXA];

int state;
int edge_u, edge_v;
int center, star_edges;
int leaf_sum;
int tri_u, tri_v, tri_w;

void sieve_spf() {
    for (int i = 2; i < MAXA; i++) spf[i] = i;
    for (int i = 2; i * i < MAXA; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAXA; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
}

int build_terms(int value, int product[], int sign[]) {
    int primes[8];
    int prime_count = 0;
    while (value > 1) {
        int p = spf[value];
        primes[prime_count++] = p;
        while (value % p == 0) value /= p;
    }
    
    int terms = 1;
    product[0] = 1;
    sign[0] = 1;
    for (int i = 0; i < prime_count; ++i) {
        for (int j = 0; j < terms; ++j) {
            product[terms + j] = product[j] * primes[i];
            sign[terms + j] = -sign[j];
        }
        terms *= 2;
    }
    return terms;
}

bool try_add(int pos, const vector<int>& a) {
    int product[128], sign[128];
    int terms = build_terms(a[pos], product, sign);
    
    int degree = 0;
    int neighbor_sum = 0;
    for (int i = 0; i < terms; ++i) {
        degree += sign[i] * cnt[product[i]];
        neighbor_sum += sign[i] * sum_idx[product[i]];
    }
    
    if (state == EMPTY) {
        if (degree == 1) {
            state = ONE_EDGE;
            edge_u = pos;
            edge_v = neighbor_sum;
        } else if (degree >= 2) {
            state = STAR;
            center = pos;
            star_edges = degree;
            leaf_sum = neighbor_sum;
        }
    } else if (state == ONE_EDGE) {
        int touch_u = std::gcd(a[pos], a[edge_u]) == 1;
        int touch_v = std::gcd(a[pos], a[edge_v]) == 1;
        if (degree != touch_u + touch_v) return false;
        
        if (degree == 1) {
            state = STAR;
            center = touch_u ? edge_u : edge_v;
            star_edges = 2;
            leaf_sum = pos + (touch_u ? edge_v : edge_u);
        } else if (degree == 2) {
            state = TRIANGLE;
            tri_u = edge_u;
            tri_v = edge_v;
            tri_w = pos;
        }
    } else if (state == STAR) {
        int touch_center = std::gcd(a[pos], a[center]) == 1;
        if (degree != touch_center) return false;
        if (touch_center) {
            star_edges++;
            leaf_sum += pos;
        }
    } else {
        if (degree != 0) return false;
    }
    
    for (int i = 0; i < terms; ++i) {
        cnt[product[i]]++;
        sum_idx[product[i]] += pos;
    }
    return true;
}

void remove_left(int pos, const vector<int>& a) {
    if (state == ONE_EDGE) {
        if (pos == edge_u || pos == edge_v) state = EMPTY;
    } else if (state == STAR) {
        if (pos == center) {
            state = EMPTY;
        } else if (std::gcd(a[pos], a[center]) == 1) {
            star_edges--;
            leaf_sum -= pos;
            if (star_edges == 1) {
                state = ONE_EDGE;
                edge_u = center;
                edge_v = leaf_sum;
            }
        }
    } else if (state == TRIANGLE) {
        if (pos == tri_u) {
            state = ONE_EDGE;
            edge_u = tri_v;
            edge_v = tri_w;
        } else if (pos == tri_v) {
            state = ONE_EDGE;
            edge_u = tri_u;
            edge_v = tri_w;
        } else if (pos == tri_w) {
            state = ONE_EDGE;
            edge_u = tri_u;
            edge_v = tri_v;
        }
    }
    
    int product[128], sign[128];
    int terms = build_terms(a[pos], product, sign);
    for (int i = 0; i < terms; ++i) {
        cnt[product[i]]--;
        sum_idx[product[i]] -= pos;
    }
}

void solve() {
    int n, q;
    if (!(cin >> n >> q)) return;
    
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    memset(cnt, 0, sizeof(int) * MAXA);
    memset(sum_idx, 0, sizeof(int) * MAXA);
    state = EMPTY;
    
    vector<int> farthest(n + 2, 0);
    int right = 0;
    for (int left = 1; left <= n; left++) {
        while (right < n && try_add(right + 1, a)) right++;
        farthest[left] = right;
        remove_left(left, a);
    }
    
    vector<int> pref(n + 2, 0);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + farthest[i];
    }
    
    vector<int> last_useful(n + 2, 0);
    int pointer = 0;
    for (int right_end = 1; right_end <= n; ++right_end) {
        while (pointer + 1 <= n && farthest[pointer + 1] < right_end) {
            ++pointer;
        }
        last_useful[right_end] = pointer;
    }
    
    for (int i = 0; i < q; i++) {
        int L, R;
        cin >> L >> R;
        int last = last_useful[R];
        if (last < L) {
            cout << 0 << "\n";
        } else {
            int res = (last - L + 1) * R - (pref[last] - pref[L - 1]);
            cout << res << "\n";
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    sieve_spf();
    int t_ = 1;
    // cin >> t_;
    while (t_--) solve();
    return 0;
}