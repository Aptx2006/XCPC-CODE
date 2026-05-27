import sys
input = lambda: sys.stdin.readline().strip()
#it = map(int, sys.stdin.read().split())
#II = lambda: next(it)

def main():
    n = int(input())
    a = list(map(str, input().split()))
    ans = ''
    for s in a:
        if s[0] <= 'c':
            ans += '2'
        elif s[0] <= 'f':
            ans += '3'
        elif s[0] <= 'i':
            ans += '4'
        elif s[0] <= 'l':
            ans += '5'
        elif s[0] <= 'o':
            ans += '6'
        elif s[0] <= 's':
            ans += '7'
        elif s[0] <= 'v':
            ans += '8'
        else:
            ans += '9'
    print(ans)

main()
