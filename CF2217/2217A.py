import sys
input = lambda: sys.stdin.readline().strip()

def main():
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    if sum(a) & 1 or ~(n * k) & 1:
        print('Yes')
    else:
        print('No')

for _ in range(int(input())):
    main()