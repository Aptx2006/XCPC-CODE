import sys
from collections import deque

input = lambda: sys.stdin.readline().strip()
# it = map(int, sys.stdin.read().split())
# II = lambda: next(it)

def main():
    N, K = map(int, input().split())
    a = [input() for _ in range(K)]
    
    MOD = 998244353
    
    trie = [{'next': {}, 'fail': 0, 'bad': False}]
    for s in a:
        u = 0
        for char in s:
            c = ord(char) - 97
            if c not in trie[u]['next']:
                trie[u]['next'][c] = len(trie)
                trie.append({'next': {}, 'fail': 0, 'bad': False})
            u = trie[u]['next'][c]
        trie[u]['bad'] = True
        
    q = deque()
    for c in range(26):
        if c in trie[0]['next']:
            v = trie[0]['next'][c]
            trie[v]['fail'] = 0
            q.append(v)
        else:
            trie[0]['next'][c] = 0
            
    while q:
        u = q.popleft()
        if trie[trie[u]['fail']]['bad']:
            trie[u]['bad'] = True
            
        for c in range(26):
            if c in trie[u]['next']:
                v = trie[u]['next'][c]
                trie[v]['fail'] = trie[trie[u]['fail']]['next'][c]
                q.append(v)
            else:
                trie[u]['next'][c] = trie[trie[u]['fail']]['next'][c]
                
    ns = []
    mp = {}
    for i in range(len(trie)):
        if not trie[i]['bad']:
            mp[i] = len(ns)
            ns.append(i)
            
    sz = len(ns)
    if sz == 0:
        print(0)
        return
        
    mat = [[0] * sz for _ in range(sz)]
    
    for i in range(sz):
        u = ns[i]
        for c in range(26):
            nxt = trie[u]['next'][c]
            if not trie[nxt]['bad']:
                mat[i][mp[nxt]] += 1
                
    def mat_mul(A, B):
        C = [[0] * sz for _ in range(sz)]
        for i in range(sz):
            for k in range(sz):
                if A[i][k]:
                    for j in range(sz):
                        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD
        return C
        
    def mat_pow(A, p):
        res = [[0] * sz for _ in range(sz)]
        for i in range(sz):
            res[i][i] = 1
        base = A
        while p > 0:
            if p % 2 == 1:
                res = mat_mul(res, base)
            base = mat_mul(base, base)
            p //= 2
        return res
        
    res_mat = mat_pow(mat, N)
    ans = sum(res_mat[0]) % MOD
    print(ans)

main()
