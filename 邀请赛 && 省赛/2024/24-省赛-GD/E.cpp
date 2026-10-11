#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
#define dbg(A) cerr << (#A) << ':' << A << endl;
#define all(A) (A).begin(), (A).end()

int n, m;

i64 solve(int n, int z) {
    //int n,z;
    //cin>>n>>z;
    vector<vector<int>>win(n+1,vector<int>(n+1));
    int ans=n,sum=0;
    vector<int>c(n+1);
    bool f=0;
    int cnt = 0;
    auto check=[&](auto &&check,int x)->void{
        for(int mask=1;mask<(1<<n);mask++){
            vector<int>t;
            for(int i=0;i<n;i++){
                if(mask&(1<<i))t.push_back(i+1);
            }
            if(t.size()!=z+1)continue;
            bool f1=0,f2=0;
            for(int i=0;i<t.size();i++){
                bool ff1=1,ff2=1;
                for(int j=0;j<t.size();j++){
                    if(i==j)continue;
                    int t1=t[i],t2=t[j];
                    if(win[t1][t2])ff1=0;
                    else ff2=0;
                }
                if(ff1)f1=1;
                if(ff2)f2=1;
            }
            if(!f1 or !f2)f=1;
            if(f==1)return;

        }
    };
    int cnt2 = 0;
    auto d=[&](auto &&d,int i,int j)->void{
        cnt2++;
        // assert(cnt2 < 100);
        //if(cnt2 == 100) exit(0);
        if(j>n){
            i++;
            j=i+1;
        }
        if(i==n){
            f=0;
            check(check,1);
            if(f==0){
                set<int>st;
                vector<int>s(n+1);
                for(int i=1;i<=n;i++){
                    for(int j=i+1;j<=n;j++){
                        if(win[i][j])s[i]++;
                        else s[j]++;
                    }
                }
                for(int i=1;i<=n;i++)st.insert(s[i]);
                ans=min(ans,(int)st.size());
            }
            return;
        }
        win[i][j]=0;
        win[j][i]=1;
        d(d,i,j+1);
        win[i][j]=1;
        win[j][i]=0;
        d(d,i,j+1);
    };
    d(d,1,2);
    //cout<<ans<<'\n';
    return ans;
}

/*
2 1 2

3 1 1
3 2 3

4 1 2
4 2 4
4 3 4

5 1 1
5 2 5
5 3 5
5 4 3

6 1 2
6 2 6
6 3 6
6 4 6
6 5 4

7 1 1
7 2 7
7 3 7
7 4 7 
7 5 5
7 6 3
*/

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    /*
    for(int i = 2; i <= 6; i++) {
        for(int j = 1; j < i; j++) {
            cout << i << ' ' << j << ' ' << solve(i, j) << endl;
        }
    }
    */

    int T = 1;
    cin >> T;
    while(T--) {
        i64 n, z;
        cin >> n >> z;
        if(n & 1) {
            if(z == 1) cout << "1\n";
            else cout << min(n, 1+(n-z)*2)<<'\n';
        }else {
            if(z == 1) cout << "2\n";
            else cout << min(n,2 + (n-z)*2)<<'\n';
        }
    }
    return 0;
}