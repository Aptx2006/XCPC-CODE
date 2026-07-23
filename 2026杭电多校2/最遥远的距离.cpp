#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

i64 T = 1, n, m, k, ans, cnt;

void solve() {
    cin >> n ;
    vector<int>a(n+1);
    vector<int> mp(n + 5);
    int minn=1e9,maxx=0;
    vector<queue<int>>Q(n+1);
    vector<int>p(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mp[a[i]]++;
        maxx=max(maxx,a[i]);
        minn=min(minn,a[i]);
        Q[a[i]].push(i);
        p[a[i]]=i;
    }
    
    int sum=mp[minn],cur=minn+1;
    bool f=0;
    while(mp[cur] != 0){
        if(mp[cur]<2)f=1;
        sum+=mp[cur++];
    }
    if(mp[minn]>2 or sum!=n or f or minn!=maxx-minn+1+(mp[minn]>1)){
        cout<<"No\n";return;
    }
    cout<<"Yes\n";
    if(Q[minn].size()==1)Q[minn].push(Q[minn].front());
    else{
        int x=Q[minn].front();
        Q[minn].pop();
        int y=Q[minn].front();
        Q[minn].push(x);
        cout<<x<<' '<<y<<'\n';
    }
    for(int i=1;i<=2;i++){
        int cur=minn;
        int x=Q[cur].front();Q[cur].pop();
        int nx=cur+1;
        while(mp[nx] != 0){
            cout<<x<<' '<<Q[nx].front()<<'\n';
            x=Q[nx].front();
            Q[nx].pop();
            cur++;
            nx++;
        }

    }
    for(int i=minn+1;mp[i] != 0;i++){
        while(!Q[i].empty()){
            cout<<Q[i].front()<<' '<<p[i-1]<<'\n';
            Q[i].pop();
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
