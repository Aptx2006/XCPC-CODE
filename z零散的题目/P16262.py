import sys
input = lambda: sys.stdin.readline().strip()

def main():
    n = int(input())
    print(max(4, n + 1))

T = int(input())
for i in range(T):
    main()