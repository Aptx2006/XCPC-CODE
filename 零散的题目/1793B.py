import sys
input = lambda: sys.stdin.readline().strip()

def main():
    mx, mn = map(int, input().split())
    print(2 * (mx - mn))
    for i in range(mn, mx):
        print(i, end = ' ')
    for i in range(mx, mn, -1):
        print(i, end = ' ')
    print('')

for _ in range(int(input())):
    main()    