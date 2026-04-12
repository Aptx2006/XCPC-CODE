import sys
input = lambda: sys.stdin.readline().strip()

def fun(total, length):
    if length == 1:
        return [(total,)]
    res = []
    for x in range(total + 1):
        for rest in fun(total - x, length - 1):
            res.append((x,) + rest)
    return res


def main():
    L, N = map(int, input().split())
    
    a = fun(L, N)
    tag = tuple([L] * N)
    dp = {tuple([0] * N): 1}
    
    for _ in range(N):
        ndp = {}
        for c, cnt in dp.items():
            for row in a:
                nsum = tuple(c[i] + row[i] for i in range(N))
                if all(x <= L for x in nsum):
                    ndp[nsum] = ndp.get(nsum, 0) + cnt
        dp = ndp
        
    print(dp.get(tag, 0))

main()
