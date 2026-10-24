#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
#define all(A) A.begin(), A.end()
i64 n, m, d, l;
const i64 P = 1e9 + 7;

struct SegmentTree{
    i64 n;
    vector<i64>tag,sum;
    SegmentTree(i64 n_) : n(n_),tag(4*n,1),sum(4*n){}

    void pull(i64 p){
        sum[p]=(sum[2*p]+sum[2*p+1])%P;
    }

    void mul(i64 p,i64 v){
        tag[p]=1LL*tag[p]*v%P;
        sum[p]=1LL*sum[p]*v%P;
    }
    void push(i64 p){
        mul(2*p,tag[p]);
        mul(2*p+1,tag[p]);
        tag[p]=1;
    }
    i64 query(i64 p,i64 l,i64 r,i64 x,i64 y){
        if(l>=y||r<=x){
            return 0;
        }
        if(l>=x&&r<=y){
            return sum[p];
        }
        i64 m=(l+r)/2;
        push(p);
        return (query(2*p,l,m,x,y)+query(2*p+1,m,r,x,y))%P;
    }

    i64 query(i64 x,i64 y){
        return query(1,0,n,x,y);
    }

    void rangeMul(i64 p,i64 l,i64 r,i64 x,i64 y,i64 v){
        if(l>=y||r<=x){
            return;
        }
        if(l>=x&&r<=y){
            return mul(p,v);
        }
        i64 m=(l+r)/2;
        push(p);
        rangeMul(2*p,l,m,x,y,v);
        rangeMul(2*p+1,m,r,x,y,v);
        pull(p);
    }

    void rangeMul(i64 x,i64 y,i64 v){
        rangeMul(1,0,n,x,y,v);
    }

    void add(i64 p,i64 l,i64 r,i64 x,i64 v){
        if(r-l==1){
            sum[p]=(sum[p]+v)%P;
            return;
        }
        i64 m=(l+r)/2;
        push(p);
        if(x<m){
            add(2*p,l,m,x,v);
        }
        else{
            add(2*p+1,m,r,x,v);
        }
        pull(p);
    }
    void add(i64 x,i64 v){
        add(1,0,n,x,v);
    }
};

void solve() {
    i64 p;
    cin >> n >> p;
    vector<i64> a(n);
    for(auto &x: a) cin >> x;
    auto b = a;
    sort(all(b));
    b.erase(unique(all(b)),b.end());
    m = b.size();
    for(auto &x: a){
        x = lower_bound(all(b), x) - b.begin();
    }
    auto qpow = [&](i64 x,i64 y){
        i64 res = 1;
        for(;y;y>>=1){
            if(y & 1) res = res * x % P;
            x = x * x % P;
        }
        return res;
    };
    
    p = p*qpow(100,P-2)%P;
    i64 q = (1 - p + P) % P;

    SegmentTree seg(m);
    seg.add(a[0], 1);
    for(int i=1;i<n;i++){
        int x = a[i];
        i64 np = (q * seg.query(0, x + 1) + p * seg.query(x + 1, m)) % P;
        seg.rangeMul(0, x + 1, p);
        seg.rangeMul(x + 1, m, q);
        seg.add(x, np);
    }
    i64 ans = 0;
    for(int i = 0; i < m; i++){
        ans = (ans + b[i] * seg.query(i, i + 1)) % P;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    //cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}
