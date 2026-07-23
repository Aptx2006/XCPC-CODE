#include<bits/stdc++.h>
using namespace std;
#define int long long
#define dbg(A) cout<<#A<<':'<<A<<'\n';
#define all(A) A.begin(),A.end()
using ld = long double;
struct nod{
    int num;
    string s;
};
signed main(){
    nod a[10];
    for(int i=1;i<=8;i++){
        cin>>a[i].s>>a[i].num;
    }
    int maxx=0,maxindex=0;
    for(int i=1;i<=4;i++){
        if(a[i].num>maxx){
            maxx=a[i].num;maxindex=i;
        }
    }
    int maxx2=0,maxxindex2=0;
     for(int i=5;i<=8;i++){
        if(a[i].num>maxx2){
            maxx2=a[i].num;maxxindex2=i;
        }
    }
    if(maxx2>maxx){
        swap(maxindex,maxxindex2);
    }
    cout<<a[maxindex].s<<" beats "<<a[maxxindex2].s;
    return 0;
}