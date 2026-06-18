import sys
input = lambda: sys.stdin.readline().strip()
it = iter(sys.stdin.read().split())
SI = lambda: next(it)
II = lambda: int(SI())

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

# 状态0: 后缀没有匹配到 ABC 的前缀
# 状态1: 后缀是 A
# 状态2: 后缀是 AB
nxt = (
    (1, 0, 0, 0), 
    (1, 2, 0, 0), 
    (1, 0, 0, 0),
)

# add[state][c]: 放入字符类 c，是否会新形成一个ABC
add = (
    (0, 0, 0, 0), 
    (0, 0, 0, 0),  
    (0, 0, 1, 0),  # s只有补C 才会形成 ABC
)

def main():
    s = SI()
    k = II()
    n = len(s)

    a = [0 if ch == 'A' else 1 if ch == 'B' else 2 if ch == 'C' else 3 for ch in s]

    # isok[i] 以i结尾的长度3的子串是否为ABC
    isok = [0] * n
    for i in range(2, n):
        isok[i] = (a[i - 2], a[i - 1], a[i]) == (0, 1, 2)

    l = -k
    w = 2 * k + 1
    INF = 10 ** 9

    #dp[state][add] = 最少替换次数
    dp = [[INF] * w for _ in range(3)]
    dp[0][-l] = 0  

    for i, oc in enumerate(a):
        cost = [1, 1, 1, 1]
        cost[oc] = 0

        ndp = [[INF] * w for _ in range(3)]

        for st in range(3):
            row = dp[st]
            tr = nxt[st]
            ad = add[st]

            for j, val in enumerate(row):
                if val == INF:
                    continue

                g = j + l  

                for ch in range(4):
                    ng = g + ad[ch] - isok[i]  
                    if l <= ng <= k:
                        ns = tr[ch]
                        nval = val + cost[ch]
                        j = ng - l
                        if nval < ndp[ns][j]:
                            ndp[ns][j] = nval

        dp = ndp

    ans = min(dp[0][k - l], dp[1][k - l], dp[2][k - l])

    out.append(-1 if ans == INF else ans)

for _ in range(II()):
    main()

print('\n'.join(map(str, out)))