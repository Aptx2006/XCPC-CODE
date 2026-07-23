#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

i64 T = 1, n, m, k, ans, cnt;
struct nod{
    int a,b,c,id;
    bool operator < (const nod&rhs)const{
        return b>rhs.b;
    }
};
void solve() {
    cin>>n>>m>>k;
    vector<nod>sub(m+2);
    vector<int>f(n+1,1);
    for(int i=1;i<=m;i++){
        cin>>sub[i].a>>sub[i].b>>sub[i].c;
        sub[i].id=i;
    }
    sub[m+1]={0,2000000005,0,0};
    vector<priority_queue<nod>>wait(n+1);
    priority_queue<nod>ready;
    priority_queue<nod>Q;//评测时间
    for(int i=1;i<=k;i++)Q.push({0,0,0,0});
    vector<int>ans(m+1);
    for(int i=1;i<=m+1;i++){
        int a=sub[i].a;
        int b=sub[i].b;
        int c=sub[i].c;

        if(f[a]==0){
            wait[a].push(sub[i]);
        }else{
            ready.push(sub[i]);
            f[a]=0;
        }

        queue<nod>tQ;
        while(Q.top().b<=b){
            nod q=Q.top();
            tQ.push(q);
            Q.pop();
            f[q.a]=1;
            if(!wait[q.a].empty()){
                f[q.a]=0;
                ready.push(wait[q.a].top());
                wait[q.a].pop();
            }
        }

        while(!tQ.empty()){
            Q.push(tQ.front());
            tQ.pop();
        }

        
        while(!ready.empty() and Q.top().b<=ready.top().b){
            nod q=Q.top();Q.pop();
            nod r=ready.top();ready.pop();
            Q.push({r.a,q.b+r.c,0,r.id});
            ans[r.id]=q.b;
            f[q.a]=1;
            if(!wait[q.a].empty()){
                f[q.a]=0;
                ready.push(wait[q.a].top());
                wait[q.a].pop();
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" \n"[i==m];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
