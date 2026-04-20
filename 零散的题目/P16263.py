import sys
input = lambda: sys.stdin.readline().strip()

def main():
    n, m = map(int, input().split())
    ans = 10**9
    N = 1 << n
    for state in range(0, N):
        ta = 0
        cnt = 0
        st = set()
        for b in range(0, n):
            if state & (1 << b):
                if (b % m) == (2 * b) % m:
                    x = b % m
                    if x in st:
                        st.remove(x)
                    else:
                        st.add(x)
                else:
                    x = b % m
                    if x in st:
                        st.remove(x)
                    else:
                        st.add(x)
                    x = 2 * b % m
                    if x in st:
                        st.remove(x)
                    else:
                        st.add(x)
                cnt += 1
        if len(st) == m:
            ans = min(ans, cnt)

    if ans == 10**9:
        print(-1)
    else:
        print(ans) 

T = int(input())
for i in range(T):
    main()