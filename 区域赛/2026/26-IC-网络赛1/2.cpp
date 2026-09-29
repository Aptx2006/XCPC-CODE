#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=500005,P=998244353;
int a[N][26],in[N],ans[N];
vector<int> G[N];

struct Node {
    Node* child[256] = {nullptr};
    int cnt = 0;
};

class Trie {
public:
    Trie() : root(new Node()) {}
    void insert(const string& word) {
        Node* node = root;
        for(char c: word) {
            if(node->child[c] == nullptr) {
                node->child[c] = new Node();
            }
            node = node->child[c];
            node->cnt++;
        }
    }
    int search(const string& pre) {
        Node* node = root;
        for(char c : pre) {
            if(node->child[c] == nullptr) {
                return 0;
            }
            node = node->child[c];
        }
        return node->cnt;
    }
private:
    Node* root;
};

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int ans=0;
        string s;cin>>s;
        for(int j=0;j<)
    } 

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) solve();
}
