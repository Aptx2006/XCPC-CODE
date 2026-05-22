import sys
input = lambda: sys.stdin.readline().strip()

def main():
    n = int(input())
    a = list(map(int, input().split()))
    k = n * 2 - a.count(1)
    if k & 1:
        print('L')
    else:
        print('Q')


T = int(input())
for i in range(T):
    main()