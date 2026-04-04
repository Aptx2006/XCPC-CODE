for _ in range(int(input())):
    a = list(map(int, input().split()))
    ans = -sum(a) + 2 * max(a)
    print(ans)
