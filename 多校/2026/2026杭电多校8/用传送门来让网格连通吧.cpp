#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = unsigned long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;

// #define DEBUG 1  // 调试开关
struct IO {
#define MAXSIZE (1 << 20)
#define isdigit(x) (x >= '0' and x <= '9')
  char buf[MAXSIZE], *p1, *p2;
  char pbuf[MAXSIZE], *pp;
#if DEBUG
#else
  IO() : p1(buf), p2(buf), pp(pbuf) {}

  ~IO() { fwrite(pbuf, 1, pp - pbuf, stdout); }
#endif
  char gc() {
#if DEBUG  // 调试，可显示字符
    return getchar();
#endif
    if(p1 == p2) p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin);
    return p1 == p2 ? ' ' : *p1++;
  }

  void read(int &x) {
    bool neg = false;
    x = 0;
    char ch = gc();
    for(; !isdigit(ch); ch = gc())
      if(ch == '-') neg = true;
    if(neg)
      for(; isdigit(ch); ch = gc()) x = x * 10 + ('0' - ch);
    else
      for(; isdigit(ch); ch = gc()) x = x * 10 + (ch - '0');
  }

  void read(char *s) {
    char ch = gc();
    for(; isspace(ch); ch = gc());
    for(; !isspace(ch); ch = gc()) *s++ = ch;
    *s = 0;
  }

  void read(char &c) { for(c = gc(); isspace(c); c = gc()); }

  void push(const char &c) {
#if DEBUG  // 调试，可显示字符
    putchar(c);
#else
    if(pp - pbuf == MAXSIZE) fwrite(pbuf, 1, MAXSIZE, stdout), pp = pbuf;
    *pp++ = c;
#endif
  }

  void write(int x) {
    bool neg = false;
    if(x < 0) {
      neg = true;
      push('-');
    }
    static int sta[40];
    int top = 0;
    do {
      sta[top++] = x % 10;
      x /= 10;
    } while (x);
    if(neg)
      while (top) push('0' - sta[--top]);
    else
      while (top) push('0' + sta[--top]);
  }

  void write(int x, char lastChar) { write(x), push(lastChar); }
} io;

struct DSU {
    vector<int> fa;
    DSU(int n) : fa(n + 1) {
        iota(fa.begin(), fa.end(), 0);
    }
    int get(int x) {
        while (x != fa[x]) {
            x = fa[x] = fa[fa[x]];
        }
        return x;
    }
    bool merge(int x, int y) {
        x = get(x), y = get(y);
        if(x == y) return false;
        fa[y] = x;
        return true;
    }
    bool same(int x, int y) {
        return get(x) == get(y);
    }
};

void solve() {
    int q;
    io.read(n); io.read(m); io.read(k); io.read(q);

    int sz = n * m;
    vector<int> pass(sz, 0);
    vector<char> buf(m + 2);

    for(int i = 0; i < n; i++) {
        io.read(buf.data());
        for(int j = 0; j < m; j++) {
            pass[i * m + j] = (buf[j] == '.');
        }
    }

    DSU dsu(sz);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int id = i * m + j;
            if(!pass[id]) continue;
            if(j + 1 < m and pass[id + 1]) dsu.merge(id, id + 1);   // 右
            if(i + 1 < n and pass[id + m]) dsu.merge(id, id + m);   // 下
        }
    }

    vector<int> pos(sz, -1);
    int ID = 0;
    for(int id = 0; id < sz; id++) {
        if(!pass[id]) continue;
        int r = dsu.get(id);
        if(pos[r] == -1) pos[r] = ID++;
        pos[id] = pos[r];
    }

    vector<int> idx(ID, -1);
    ID = 0;
    vector<pair<int, int>> edge;

    for(int i = 0; i < k; i++) {
        int x1, y1, x2, y2;
        io.read(x1); io.read(y1); io.read(x2); io.read(y2);

        int ce = pos[(x1 - 1) * m + (y1 - 1)];  
        int cx = pos[(x2 - 1) * m + (y2 - 1)];  

        int u = idx[ce];
        if(u == -1) u = idx[ce] = ID++;
        int v = idx[cx];
        if(v == -1) v = idx[cx] = ID++;

        edge.push_back({u, v});
    }

    vector<vector<int>> G(ID);
    for(auto &e : edge) G[e.first].push_back(e.second);

    vector reach(ID, vector<bool>(ID, 0));
    for(int s = 0; s < ID; s++) {
        vector<bool> vis(ID, 0);
        queue<int> Q;
        Q.push(s);
        vis[s] = 1;

        while(!Q.empty()) {
            int u = Q.front();
            Q.pop();
            reach[s][u] = 1;
            for(int v : G[u]) {
                if(!vis[v]) {
                    vis[v] = 1;
                    Q.push(v);
                }
            }
        }
    }

    for(int i = 0; i < q; i++) {
        int x1, y1, x2, y2;
        io.read(x1); io.read(y1); io.read(x2); io.read(y2);
        int cs = pos[(x1 - 1) * m + (y1 - 1)];
        int ct = pos[(x2 - 1) * m + (y2 - 1)];
        int res = 0;
        if(cs == ct) {
            res = 1;  
        } else {
            int u = idx[cs], v = idx[ct];
            if(u != -1 and v != -1 and reach[u][v]) res = 1;
        }
        io.write(res, '\n');
    }
}

int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    for(io.read(T); T--; solve());
    return 0;
}
