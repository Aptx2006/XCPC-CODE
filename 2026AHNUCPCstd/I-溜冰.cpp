#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

struct point {
    i64 x, y, id;
};

const int N = 2e5 + 8;
i64 n, m, ans, cnt, k, l, r;
point a[N];

void solve(){
    i64 stx, sty, edx, edy;
    cin >> n >> stx >> sty >> edx >> edy;
    vector<point> Gx, Gy;
    vector<point> p;
    p.push_back({stx, sty, 0});
    for(i64 i = 1; i <= n; i++){
        cin >> a[i].x >> a[i].y;
        a[i].id = i;
        Gx.push_back({a[i].x, a[i].y, a[i].id});
        Gy.push_back({a[i].x, a[i].y, a[i].id});
    }
    sort(Gx.begin(), Gx.end(), [](point a, point b){
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    });
    sort(Gy.begin(), Gy.end(), [](point a, point b){
        return a.y < b.y || (a.y == b.y && a.x < b.x);
    });    
    map<pair<i64, i64>, i64> mp;
    queue<point> Q;
    Q.push({stx, sty, 1});
    mp[{stx, sty}] = 1;
    while(!Q.empty()){
        auto [x, y, st] = Q.front();
        Q.pop();
        if(x == edx && y == edy) break;
        point t = {x, y + 1, st};
        auto itx = lower_bound(Gx.begin(), Gx.end(), t, [](const point& a, const point& b){
            return a.x < b.x || (a.x == b.x && a.y < b.y);
        });
        point nw;
        if(itx != Gx.end()){
            nw = *itx;
            if(nw.x == x){
                if(!mp.count({nw.x, nw.y - 1})){
                    mp[{nw.x, nw.y - 1}] = st + 1;
                    Q.push({nw.x, nw.y - 1, st + 1});
                }
            }
            
        }
        if(itx != Gx.begin()){
            itx--;
            nw = *itx;
            if(nw.x == x){
                if(!mp.count({nw.x, nw.y + 1})){
                    mp[{nw.x, nw.y + 1}] = st + 1;
                    Q.push({nw.x, nw.y + 1, st + 1});
                }
            }
        }
        t = {x + 1, y, st};
        auto ity = lower_bound(Gy.begin(), Gy.end(), t, [](const point& a, const point& b){
            return a.y < b.y || (a.y == b.y && a.x < b.x);
        });
        if(ity != Gy.end()){
            nw = *ity;
            if(nw.y == y){
                if(!mp.count({nw.x - 1, nw.y})){
                    mp[{nw.x - 1, nw.y}] = st + 1;
                    Q.push({nw.x - 1, nw.y, st + 1});
                }
            }
            
        }
        if(ity != Gy.begin()){
            ity--;
            nw = *ity;
            if(nw.y == y){
                if(!mp.count({nw.x + 1, nw.y})){
                    mp[{nw.x + 1, nw.y}] = st + 1;
                    Q.push({nw.x + 1, nw.y, st + 1});
                }
            }
        }
    }
    cout << mp[{edx, edy}] - 1 << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)  solve();
    return 0;
}
