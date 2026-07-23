import sys
#input = lambda: sys.stdin.readline().strip()
it = map(int, sys.stdin.read().split())
II = lambda: next(it)

def main():
    x = II()
    s = 'HelloWorld'
    print(s[:x - 1] + s[x:])

main()
