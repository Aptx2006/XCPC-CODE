import sys
import math

input = lambda: sys.stdin.readline().strip()

def main():
    n, m, a, b = map(int, input().split())
    if math.gcd(n, a) == 1 and math.gcd(m, b) == 1 and math.gcd(n, m) <= 2:
        print("YES")
    else:
        print("NO")

for _ in range(int(input())):
    main()
