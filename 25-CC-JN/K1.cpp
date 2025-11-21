#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(A) A.begin(),A.end()
#define dbg(A) cout<<#A<<':'<<A<<endl;
const int N = 5e5+5,M=1e9+7;
int n,m,a[N];
void solve(){
    cin >> n;
    vector<int>mp(n+1,2);
    vector<int>ans(n+10,0);
    mp[0] = -1;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        mp[a[i]]--;
    }
    int ct2 = count(all(mp),0),ct1 = count(all(mp),1);//两张都有，有一张
    if(mp[a[1]] == 0){
        cout<<"1\n";
        vector<int>id[n+5],use;
        unordered_set<int>st;
        for(int i=1;i<=n;i++){
            if(mp[a[i]]==0)
                id[a[i]].push_back(i);
            else if(mp[a[i]]==1)
                use.push_back(a[i]);
            if(mp[i]==2)
                st.insert(i);
        }
        //dbg(st.size())
        for(auto v:id){
            if(v.empty() or v[0]==1) continue;
            while(v[0]==1 or ans[v[0]-1]) v[0]++;
            ans[v[0]-1] = *st.begin();
            while(ans[v[1]-1]) v[1]++;
            ans[v[1]-1] = *st.begin();
            st.erase(st.begin());
        }
            auto v = id[a[1]];
            while(v[0]==1 or ans[v[0]-1]) v[0]++;
            ans[v[0]-1] = *st.begin();
            while(ans[v[1]-1]) v[1]++;
            ans[v[1]-1] = *st.begin();
            st.erase(st.begin());
        int p = 0;
        for(int i=1;i<=n;i++){
            if(ans[i]) continue;
            ans[i] = use[p++];
        }
        for(int i=1;i<=n;i++) cout<<ans[i]<<' ';cout<<'\n';
        return;
    }
    cout<<"0\n";
    if(ct2==0){
        for(int i=1;i<=n;i++)
            cout<<a[i]<<" \n"[i==n];
        return;
    }
    vector<int>id[n+5],use;
    unordered_set<int>st;
    for(int i=1;i<=n;i++){
        if(mp[a[i]]==0)
            id[a[i]].push_back(i);
        else if(mp[a[i]]==1)
            use.push_back(a[i]);
        if(mp[i]==2)
            st.insert(i);
    }
    //dbg(st.size())
    for(auto v:id){
        if(v.empty()) continue;
        ans[v[0]-1] = ans[v[1]-1] = *st.begin();
        st.erase(st.begin());
    }
    int p = 0;
    for(int i=1;i<=n;i++){
        if(ans[i]) continue;
        ans[i] = use[p++];
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<' ';cout<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T = 1; cin >> T;
    while(T--) solve();
}