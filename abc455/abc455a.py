import sys
input = lambda: sys.stdin.readline().strip()

a, b, c= map(int, input().split())
if a != b and b == c:
    print('Yes')
else:
    print('No')