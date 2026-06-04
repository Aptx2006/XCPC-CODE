import sys, math
input = lambda: sys.stdin.readline().strip()
it = map(int, sys.stdin.read().split())
II = lambda: next(it)

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    n, m = II(), II()    
    if m == 0:
        print(0)
        return
    G = list([] for _ in range(n))
    for _ in range(m):
        u, v = II() - 1, II() - 1
        G[u].append(v)
        G[v].append(u)
        
    dp = list([0] * n for _ in range(1 << n))
    for i in range(n):
        dp[1 << i][i] = 1
        
    ans = 0
    for mask in range(1, 1 << n):
        row = dp[mask]
        v = (mask & -mask).bit_length() - 1
        
        for i in range(v, n):
            val = row[i]
            if val == 0:
                continue
            
            for j in G[i]:
                if j == v:
                    ans += val
                elif j > v and not ((mask >> j) & 1):
                    dp[mask | (1 << j)][j] += val

    out.append((ans - m) // 2)

main()

print('\n'.join(map(str, out)))
