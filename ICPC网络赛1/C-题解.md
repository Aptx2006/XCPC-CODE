# C. Permutation Inversions

## 1. 题面简述

现在有一个未知排列 $p_1,p_2,\ldots,p_n$，题目给出 $m$ 条限制。

每条限制包含一个区间 $[l_i,r_i]$，以及区间内所有下标组成的一个排列

$$
q_{i,1},q_{i,2},\ldots,q_{i,r_i-l_i+1},
$$

它表示

$$
p_{q_{i,1}}<p_{q_{i,2}}<\cdots<p_{q_{i,r_i-l_i+1}}.
$$

要求构造一个满足全部限制，并且逆序对数量最少的排列。如果不存在合法排列，输出 `-1`。

## 2. 分析

首先只考虑怎样满足大小关系。对于一条限制，只需要按照给出的顺序连边：

$$
q_1\to q_2\to\cdots\to q_k.
$$

如果最后得到的图中存在环，说明某些位置互相要求比对方小，不可能构造出合法排列，直接输出 `-1`。

如果图中没有环，我们求出一个拓扑序

$$
v_1,v_2,\ldots,v_n,
$$

然后令

$$
p_{v_i}=i,
$$

就可以满足所有边对应的大小关系。

接下来考虑怎样让逆序对最少。对于两个原下标 $i<j$，如果在拓扑序中 $j$ 出现在 $i$ 前面，那么最终就有 $p_i>p_j$，产生一个逆序对。所以我们希望拓扑序尽量按照原下标从小到大排列，由此想到使用小根堆维护所有入度为零的点，每次取编号最小的点。

但是需要注意，对于一般的有向无环图，字典序最小拓扑序不一定拥有最少逆序对。本题能够这样做，是因为每条限制会将一个完整连续区间中的所有位置全部排好顺序。

考虑三个下标 $i<j<k$。如果限制能够推出 $k$ 必须在 $i$ 前面，那么从 $k$ 到 $i$ 的路径一定会经过一条跨过位置 $j$ 的边。这条边来自某个完整区间，而 $j$ 也在这个区间中，所以该区间一定同时确定了 $j$ 与这条边两端的顺序。由此可知，必然满足下面两种情况中的至少一种：

$$
k\to j\qquad\text{或}\qquad j\to i.
$$

现在假设小根堆得到的拓扑序中出现了一个逆序对 $i<j$，即 $j$ 比 $i$ 更早出队。当 $j$ 出队时，$i$ 还不是零入度点。沿着 $i$ 的前驱一直向前，可以找到剩余图中的一个零入度点 $k$，并且 $k$ 能够到达 $i$。

小根堆选择了 $j$ 而没有选择 $k$，说明 $k>j$。此时有

$$
i<j<k,
$$

并且 $k\to i$。根据上面的区间性质，要么 $k\to j$，要么 $j\to i$。第一种情况与 $j$ 已经是零入度点矛盾，因此只能是

$$
j\to i.
$$

也就是说，小根堆拓扑序中产生的每一个逆序对，都是题目限制强制要求的。任何合法排列都无法消除这些逆序对，所以该拓扑序的逆序对数量一定最少。

每条长度为 $len$ 的限制只需要加入 $len-1$ 条边。设所有限制长度之和为 $S$，建图复杂度为 $O(S)$，小根堆拓扑排序复杂度为 $O(n\log n+S)$，空间复杂度为 $O(n+S)$。

如果只使用普通队列进行拓扑排序，虽然也可以构造合法排列，但是不能保证逆序对最少；如果暴力枚举所有拓扑序，复杂度最坏为 $O(n!)$，只能用于小数据验证。

## 3. 代码

<details>
<summary>点击查看代码</summary>

```cpp
#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;

void solve() {
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    vector<int> deg(n + 1);
    for (int i = 1; i <= m; i++) {
        int l, r, pre;
        cin >> l >> r >> pre;
        for (int j = l + 1, x; j <= r; j++) {
            cin >> x;
            g[pre].push_back(x);
            deg[x]++;
            pre = x;
        }
    }

    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 1; i <= n; i++) {
        if (!deg[i]) q.push(i);
    }

    vector<int> p(n + 1);
    int cur = 0;
    while (!q.empty()) {
        int x = q.top();
        q.pop();
        p[x] = ++cur;
        for (auto y: g[x]) {
            if (!--deg[y]) q.push(y);
        }
    }

    if (cur < n) {
        cout << -1 << '\n';
        return;
    }
    for (int i = 1; i <= n; i++) {
        cout << p[i] << " \n"[i == n];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
```

</details>

## Tag

`拓扑排序` `优先队列` `贪心` `构造` `逆序对`
