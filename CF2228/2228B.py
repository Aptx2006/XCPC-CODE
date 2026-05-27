import sys

it = map(int, sys.stdin.buffer.read().split())
II = lambda: next(it)

def main():
    t = II()
    out = []
    for _ in range(t):
        n, x1, x2, k = II(), II(), II(), II()
        if n <= 3:
            out.append('1')
            continue
        d = abs(x1 - x2)
        d = min(d, n - d)
        out.append(str(d + k))
    print("\n".join(out))

main()
