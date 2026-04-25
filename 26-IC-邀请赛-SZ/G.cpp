#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int n, m, T, stx, sty;
char e[105][105];
void solve() {
    int x, y;
    cin >> n >> m >> x >> y;
    if(n % 2 == 0) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if (j == 1) {
                    if (i < n) e[i][j] = 'D';
                    else e[i][j] = 'R';
                } else if (i == 1) {
                    e[i][j] = 'L';
                } else if (i % 2 == 0) {
                    if (j < m) e[i][j] = 'R';
                    else e[i][j] = 'U';
                } else {
                    if (j > 2) e[i][j] = 'L';
                    else e[i][j] = 'U';
                }
            }
        }
    }else if(m % 2 == 0) {
        for(int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (i == n) {
                    if (j < m) e[i][j] = 'R';
                    else e[i][j] = 'U';
                } else if (j == 1) {
                    e[i][j] = 'D';
                } else if (j % 2 == 0) {
                    if (i > 1) e[i][j] = 'U';
                    else e[i][j] = 'L';
                } else {
                    if (i < n - 1) e[i][j] = 'D';
                    else e[i][j] = 'L';
                }
            }
        }
    }else {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(i == n) {
                    if (j < m) e[i][j] = 'R';
                    else e[i][j] = 'U';
                }else if (j >= 3) {
                    if(j & 1) {
                        if (i > 1) e[i][j] = 'U';
                        else e[i][j] = 'L';
                    }else {
                        if (i < n - 1) e[i][j] = 'D';
                        else e[i][j] = 'L';
                    }
                }else if (i == 1 and j == 1) {
                    e[i][j] = 'D';
                }else if (j == 1) {
                    if (i % 2 != 0) e[i][j] = 'R';
                    else e[i][j] = 'D';
                }else {
                    if (i % 2 != 0) e[i][j] = 'D';
                    else e[i][j] = 'L';
                }
            }
        }
    }
    for(int k = 1; k < n * m; ++k) {
        int tx, ty; 
        cin >> tx >> ty;
        if(n & 1 and m & 1) {
            if (e[1][2] == 'D' and tx == 1 and ty == 1) e[1][2] = 'L';
            if (e[1][2] == 'L' and tx == 2 and ty == 2) e[1][2] = 'D';
        }
        while(x != tx or y != ty) {
            char d = e[x][y];
            cout << d;
            x += (d == 'D') - (d == 'U');
            y += (d == 'R') - (d == 'L');
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
}
