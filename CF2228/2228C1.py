import sys

it = map(int, sys.stdin.buffer.read().split())
II = lambda: next(it)

def main():
    t = II()
    out = []
    for _ in range(t):
        a, n = II(), II()
        d1, d2 = II(), II()

        sa = str(a)
        L = len(sa)
        ds = [d1, d2]
        
        c = []
        
        if L > 1:
            cand = int(str(d2) * (L - 1))
            c.append(cand)
            
        sts = [d for d in ds if d > 0]
        if sts:
            cand = int(str(sts[0]) + str(d1) * L)
            c.append(cand)
            
        def dfs(idx, cval, f1, f2):
            if idx == L:
                c.append(cval)
                return
            
            if f1:
                dfs(idx + 1, cval * 10 + d2, True, False)
                return
            if f2:
                dfs(idx + 1, cval * 10 + d1, False, True)
                return
            
            target = int(sa[idx])
            for d in ds:
                if idx == 0 and d == 0 and L > 1:
                    continue
                if d < target:
                    dfs(idx + 1, cval * 10 + d, True, False)
                elif d > target:
                    dfs(idx + 1, cval * 10 + d, False, True)
                else:
                    dfs(idx + 1, cval * 10 + d, False, False)
        
        dfs(0, 0, False, False)
        
        ans = min(abs(a - c) for c in c)
        out.append(str(ans))

    print("\n".join(out))

main()
