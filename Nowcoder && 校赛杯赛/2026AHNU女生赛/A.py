n = int(input())
s = bin(n)
if s.count('11'):
    print('NO')
else:
    print('YES')
