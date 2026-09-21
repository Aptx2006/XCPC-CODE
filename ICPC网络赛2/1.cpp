#include<bits/stdc++.h>
using namespace std;

int n,m;
map<string,int> mp;

void init(){
    mp["WrongProblem"]=100;
    mp["SameProblem"]=30;
    mp["UnreasonableLimitForProblem"]=5;
    mp["WeakTestsForProblem"]=3;
    mp["BadProblem"]=1;
}

void A(){
    cin>>n>>m;
    int tot=0;
    while(n--){
        string s;
        cin>>s;
        if(s=="UnreasonableProblemArrangement"){
            tot+=10;
            continue;
        }
        if(s[s.size()-1]>'L'||s[s.size()-1]<'A')continue;
        s=s.substr(0,s.size()-1);
        if(mp.count(s))tot+=mp[s];

    }
    if(tot>m)cout<<"Joker\n";
    else cout<<"Judger\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    cin>>t;
    init();
    while(t--){
        A();
    }
}