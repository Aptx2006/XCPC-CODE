import sys
input = lambda: sys.stdin.readline().strip()


fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    n,m,k = map(int,input().split())
    a=list(map(int,input().split()))
    b=list(range(1,n+1))
    p=0
    st=set()
    cnt=0
    for x in a:
        if x in st:
            cnt+=1
        else:
            st.add(x)
        if cnt == k:
            cnt=0
            while p < n and b[p] in st:
                p+=1
            if p < n:
                st.add(b[p])

    out.append(len(st))

for _ in range(1):
    main()

print('\n'.join(map(str, out)))
