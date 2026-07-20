#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;

using score = array<int, 6>;

int tonum(char c) {
    if('2' <= c and c <= '9') return c - '0';
    if(c == 'T') return 10;
    if(c == 'J') return 11;
    if(c == 'Q') return 12;
    if(c == 'K') return 13;
    return 14; //A
}

int tocolor(char c) {
    if(c == 'C') return 0;
    if(c == 'D') return 1;
    if(c == 'H') return 2;
    return 3; //S
}

int toid(const string &s) {
    int n = tonum(s[0]);
    int r = tocolor(s[1]);
    return (n - 2) * 4 + r;
}

int tonum_(int id) {
    return id / 4 + 2;
}

int tocolor_(int id) {
    return id % 4;
}

/*
    Pair: 一对
    Two a: 两个对子
    Three of a kind: 三带一带一
    Straight: 顺子
    Flush: 同花
    Full house：三带二
    Four of a kind: 四带一
    Straight flush
    Royal flush: 10JQKA
*/

score work(const vector<int> &card) {
    int mp[15]{};
    vector<int> num, color;

    for(int id : card) {
        int n = tonum_(id);
        int c = tocolor_(id);
        mp[n]++;
        num.push_back(n);
        color.push_back(c);
    }

    sort(num.rbegin(), num.rend());

    bool flush = true;
    for(int i = 1; i < 5; i++) {
        if(color[i] != color[0]) {
            flush = false;
        }
    }

    int dis = 0;
    for(int n = 2; n <= 14; n++) {
        dis += mp[n] > 0;
    }

    bool straight = false;
    int len = 0;

    if(dis == 5) {
        if(num[0] - num[4] == 4) {
            straight = true;
            len = num[0];
        } else if(num == vector<int>{14, 5, 4, 3, 2}) {
            straight = true;
            len = 5;
        }
    }

    int four = -1;
    int three = -1;
    vector<int> a, b; //a放对子 b放单张

    for(int n = 14; n >= 2; n--) {
        if(mp[n] == 4) {
            four = n;
        } else if(mp[n] == 3) {
            three = n;
        } else if(mp[n] == 2) {
            a.push_back(n);
        } else if(mp[n] == 1) {
            b.push_back(n);
        }
    }

    score res{};

    if(straight and flush and len == 14) {
        res[0] = 9;
        return res;
    }
    if(straight and flush) {
        res[0] = 8;
        res[1] = len;
        return res;
    }
    if(four != -1) {
        res[0] = 7;
        res[1] = four;
        res[2] = b[0];
        return res;
    }
    if(three != -1 and !a.empty()) {
        res[0] = 6;
        res[1] = three;
        res[2] = a[0];
        return res;
    }
    if(flush) {
        res[0] = 5;
        for(int i = 0; i < 5; i++) {
            res[i + 1] = num[i];
        }
        return res;
    }
    if(straight) {
        res[0] = 4;
        res[1] = len;
        return res;
    }
    if(three != -1) {
        res[0] = 3;
        res[1] = three;
        for(int i = 0; i < (int)b.size(); i++) {
            res[i + 2] = b[i];
        }
        return res;
    }
    if(a.size() == 2) {
        res[0] = 2;
        res[1] = a[0];
        res[2] = a[1];
        res[3] = b[0];
        return res;
    }
    if(a.size() == 1) {
        res[0] = 1;
        res[1] = a[0];
        for(int i = 0; i <(int)b.size(); i++) {
            res[i + 2] = b[i];
        }
        return res;
    }
    res[0] = 0;
    for(int i = 0; i < 5; i++) {
        res[i + 1] = num[i];
    }
    return res;
}

void solve() {
    vector<int> my(4), he(4);
    bool mp[52]{};

    for(int i = 0; i < 4; i++) {
        string s;
        cin >> s;
        my[i] = toid(s);
        mp[my[i]] = true;
    }

    for(int i = 0; i < 4; i++) {
        string s;
        cin >> s;
        he[i] = toid(s);
        mp[he[i]] = true;
    }

    array<score, 52> sc1, sc2;

    for(int id = 0; id < 52; id++) {
        if(mp[id]) continue;

        vector<int> hand = my;
        hand.push_back(id);
        sc1[id] = work(hand);

        hand = he;
        hand.push_back(id);
        sc2[id] = work(hand);
    }

    bool flag1 = true, flag2 = false;

    for(int i = 0; i < 52; i++) {
        if(mp[i]) continue;

        score best{};
        bool ok = false;

        for(int j = 0; j < 52; j++) {
            if(mp[j] or j == i) continue;
            if(!ok or best < sc1[j]) {
                ok = true;
                best = sc1[j];
            }
        }

        if(!(best > sc2[i])) {
            flag1 = false;
        }
        if(sc2[i] > best) {
            flag2 = true;
        }
    }

    if(flag1) {
        cout << "WoYaoYanPai\n";
    } else if(flag2) {
        cout << "GeiWoCaPiXie\n";
    } else {
        cout << "PaiMeiYouWenTi\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}