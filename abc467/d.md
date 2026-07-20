用 $L_{XY}$ 表示线段 $XY$ 的中垂线
题目即为判断 $L_{PQ}$ $L_{RS}$ 有没有公共点
则：
$$ PQ=\vec a=Q-P, RS=\vec b=S-R$$
若：
$$\vec a\times\vec b\ne0$$
则 $PQ$ 与 $RS$ 不平行， $L_{PQ}$ $L_{RS}$ 一定相交，输出 Yes
若平行，$L_{PQ}$ $L_{RS}$ 一定平行，判断重合：
设$PQ$与$RS$的中点分别为 $M_1,M_2$
则
$$ M_1M_2=\vec c=M2-M1$$
若：
$$\vec a\cdot \vec c=0$$
则说明$L_{PQ}$ $L_{RS}$重合，输出 Yes
除了这两种情况，都输出 No

```cpp
void solve() {
    Point P, Q, R, S;
    cin >> P.x >> P.y >> Q.x >> Q.y >> R.x >> R.y >> S.x >> S.y;
    Vector a = Q - P, b = S - R;
    Vector c = { 
        R.x + S.x - P.x - Q.x,
        R.y + S.y - P.y - Q.y
    };
    int ok = 1;
    if (cross(a, a) != 0) {
        ok = 1;
    } else {
        ok = (dot(a, c) == 0);
    }
    cout << (ok? "Yes" : "No") << '\n';
}
```