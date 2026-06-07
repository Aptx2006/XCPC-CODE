import sys
input = lambda: sys.stdin.readline().strip()


fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    n=int(input())
    a=list(map(int,input().split()))
    st = set()
    for x in a:
        if x % 3 == 0:
            while x:
                if x % 3 != 0 or x in st:
                    break
                st.add(x)
                x//=3
    out.append(len(st))

for _ in range(1):
    main()

print('\n'.join(map(str, out)))
