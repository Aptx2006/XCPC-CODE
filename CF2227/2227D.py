import sys
input = lambda: sys.stdin.readline().strip()
# it = map(int, sys.stdin.read().split())
# II = lambda: next(it)p()

def main():
    n = int(input())
    a = list(map(int, input().split()))

    s = [0] * (n + 5)
    v = 0
    m = 0

    sz = 2 * n
    for i in range(sz):
        l = i
        r = i
        while l >= 0 and r < sz and a[l] == a[r]:
            l -= 1
            r += 1
        l += 1
        r -= 1
        if l <= r:
            v += 1
            for j in range(l, r + 1):
                s[a[j]] = v
            x = 0
            while s[x] == v:
                x += 1
            if x > m:
                m = x

        if i + 1 < sz:
            l = i
            r = i + 1
            while l >= 0 and r < sz and a[l] == a[r]:
                l -= 1
                r += 1
            l += 1
            r -= 1
            if l <= r:
                v += 1
                for j in range(l, r + 1):
                    s[a[j]] = v
                x = 0
                while s[x] == v:
                    x += 1
                if x > m:
                    m = x

    print(m)

for _ in range(int(input())):
	main()
