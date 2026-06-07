import sys
input = lambda: sys.stdin.readline().strip()


fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    n = int(input())
    s = input()
    s += s
    cnt = []
    ct=1
    for i in range(1,2*n):
        if s[i]==s[i-1]:
            ct+=1
        else:
            cnt.append(ct)
            ct=1
    if ct:
        cnt.append(ct)
    if max(cnt) > 2:
        out.append(0)
        return
    c2 = cnt.count(2)
    c2 = (c2 + 1) // 2
    if c2 > 1:
        out.append(0)
    elif c2 == 1:
        out.append(1)
    else:
        out.append(n)

for _ in range(1):
    main()

print('\n'.join(map(str, out)))
