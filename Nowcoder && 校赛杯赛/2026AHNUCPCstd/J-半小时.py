t = int(input())
a = list(map(int, input().split()))
for x in a:
    while x & 1 and x > 1:
        x >>= 1
    print(x * 30)
