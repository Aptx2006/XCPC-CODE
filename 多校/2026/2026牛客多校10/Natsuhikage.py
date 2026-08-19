import math
import sys
input = lambda: sys.stdin.readline().strip()
it = iter(sys.stdin.read().split())
SI = lambda: next(it)
II = lambda: int(SI())

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    sx, sy, ax, ay, bx, by = [II() for _ in range(6)]
    n = math.sqrt(ax * ax + ay * ay)
    L = math.atan2(ay, ax) % (2 * math.pi)
    R = math.atan2(by, bx) % (2 * math.pi)
    if R < L:
        R += 2 * math.pi

    def fun(x):
        return abs(n * math.cos(x) - n * math.sin(x) * (sx / sy))

    a = [L, R]
    for i in [math.atan2(-sx, sy), math.atan2(sy, sx)]:
        for k in range(-2, 4):
            x = (i % math.pi) + k * math.pi
            if L - 1e-9 <= x <= R + 1e-9:
                a.append(x)

    ans = [fun(x) for x in a]
    out.append(f"{min(ans):.10f} {max(ans):.10f}")

for _ in range(II()):
    main()

print('\n'.join(map(str, out)))
