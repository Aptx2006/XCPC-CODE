import sys
input = lambda: sys.stdin.readline().strip()

# test github -> gitee
# github <- gitee
# 这次推送没有具体更新，仅用于测试gitee的同步功能是否正常

def change(a, b, l):
    return b, l - 1 - a

def main():
    n = int(input())
    q = int(input())
    ops = []
    for _ in range(q):
        op, x, y, l = map(int, input().split())
        ops.append((op, x, y, l))

    d = int(input())
    for _ in range(d):
        x, y = map(int, input().split())
        for op, x0, y0, l in reversed(ops):
            if x0 <= x < x0 + l and y0 <= y < y0 + l:
                a, b = x - x0, y - y0
                if op == 1:
                    for _ in range(3):
                        a, b = change(a, b, l)
                else:
                    a, b = change(a, b, l)
                x, y = x0 + a, y0 + b
        print((x - 1) * n + y)

main()