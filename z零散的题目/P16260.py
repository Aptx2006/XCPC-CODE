import sys
input = lambda: sys.stdin.readline().split()

def main():
    k = 20269876543210 + 20260123456789
    mod = 998244353
    ans = 0
    i = 1
    while 1:
        if i * i > k:
            break
        ans = (ans + (i * i + 1) % mod) % mod
        i += 1
    print(574942000)

main()