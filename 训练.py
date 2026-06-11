import random
import sys

def solve_for_output(n, a, b):
    """模拟 std 的判断逻辑，返回 'Yes' 或 'No'"""
    last = max(a[0], b[0])
    for i in range(1, n):
        mx = max(a[i], b[i])
        mn = min(a[i], b[i])
        if mx <= last:
            last = mx
        elif mn <= last:
            last = mn
        else:
            return "No"
    return "Yes"

def main():
    # 总 n = 1e6，这里只生成一个测试用例
    T = 1
    n = 1_000_000
    MAX_VAL = 10**9  # a,b 的范围

    random.seed(20240101)  # 固定种子，可复现；需要随机可注释掉

    a = [0] * n
    b = [0] * n
    for i in range(n):
        a[i] = random.randint(1, MAX_VAL)
        b[i] = random.randint(1, MAX_VAL)

    ans = solve_for_output(n, a, b)

    # 写入 hack.in
    with open("hack.in", "w") as f:
        f.write(f"{T}\n")
        f.write(f"{n}\n")
        for i in range(n):
            f.write(f"{a[i]} {b[i]}\n")

    # 写入 hack.out
    with open("hack.out", "w") as f:
        f.write(ans + "\n")

    print("hack.in and hack.out generated.")
    print(f"T={T}, total n={n}, result={ans}")

if __name__ == "__main__":
    main()
