import sys
input = lambda: sys.stdin.readline().strip()
it = iter(sys.stdin.read().split())
SI = lambda: next(it)
II = lambda: int(SI())

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    a1,b1,a2,b2=[3],[],[3],[]
    for i in range(100001):
        a1.append(0)
        a2.append(0)
        b1.append(3)
        b2.append(3)
    b2[-1]=4
    for num in a1:
        print(num,end='')
    print(' ')
    for num in b1:
        print(num,end='')
    print(' ')
    for num in a2:
        print(num,end='')
    print(' ')
    for num in b2:
        print(num,end='')


main()

print('\n'.join(map(str, out)))
