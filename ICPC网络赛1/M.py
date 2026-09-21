n, m = map(int, input().split())
st1 = set()
st2 = set()
for i in range(n):
    st1.add(input())
for i in range(m):
    s = input()
    if s in st1 and s not in st2:
        print('OK')
    elif s in st1 and s in st2:
        print('REPEAT')
    elif s not in st1:
        print('WRONG')
    st2.add(s) 
