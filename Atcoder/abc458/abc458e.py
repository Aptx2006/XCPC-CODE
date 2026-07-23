import sys
input = lambda: sys.stdin.readline().strip()
# it = map(int, sys.stdin.read().split())
# II = lambda: next(it)

def main():
    X1, X2, X3 = map(int, input().split())
    
    MOD = 998244353
    
    MAX = X1 + X2 + X3 + 5
    fact = [1] * MAX
    inv = [1] * MAX
    
    for i in range(1, MAX):
        fact[i] = (fact[i-1] * i) % MOD
        
    inv[MAX-1] = pow(fact[MAX-1], MOD - 2, MOD)
    for i in range(MAX-2, -1, -1):
        inv[i] = (inv[i+1] * (i + 1)) % MOD
        
    def comb(n, r):
        if r < 0 or r > n:
            return 0
        return fact[n] * inv[r] % MOD * inv[n-r] % MOD

    ans = 0
    for k1 in range(1, min(X1, X2 + 1) + 1):
        term1 = comb(X1 - 1, k1 - 1)
        term2 = comb(X2 + 1, k1)
        term3 = comb(X2 + X3 - k1, X3)
        ans = (ans + term1 * term2 % MOD * term3 % MOD) % MOD
        
    print(ans)

main()
