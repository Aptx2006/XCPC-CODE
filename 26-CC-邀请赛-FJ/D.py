import sys
input = lambda: sys.stdin.readline().strip()
# it = map(int, sys.stdin.read().split())
# II = lambda: next(it)

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    s = list(map(int, input()))
    n = len(s)
    s = [0] + s
    cnt = s.count(1)
    ans = list(range(n + 1))

    if ~cnt & 1:
        s[1] = 1 ^ s[1]
    
    B = 2 ** 40
    for i in range(1, n + 1):
        if s[i]:
            ans[i] = i ^ B

    sum = 0
    for x in ans[1:]:
        sum ^= x
    chk = []
    for x in ans[1:]:
        if x ^ sum < x:
            chk.append(1)
        else:
            chk.append(0)
    #print(*chk)
    print(*ans[1:])

main()

print('\n'.join(map(str, out)))
