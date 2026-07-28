import sys
input = lambda: sys.stdin.readline().strip()
it = iter(sys.stdin.read().split())
SI = lambda: next(it)
II = lambda: int(SI())

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []


def 矩形(a, b, x, y):
    dx = a - x
    dy = b - y
    if abs(dx) <= 1 and abs(dy) <= 1:
        return True
    if dx == 0 and abs(dy) == 2:
        return True
    if dy == 0 and abs(dx) == 2:
        return True
    return False

def 剑雨(x, y):
    return (0 <= x <= 4) and (-2 <= y <= 2)

def main():
    n = II() 
    st = set()
    Q = [] 
    
    for _ in range(n):
        x, y = II(), II()
        st.add((x, y))
        Q.append([x, y, 1, 0])
        
    m = II()
    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]
    
    for _ in range(m):
        x, y = II(), II()
        st.add((x, y))
        if 剑雨(x, y):
            Q.append([x, y, 1, 0])
            for j in range(4):
                nx, ny = x + dx[j], y + dy[j]
                if (nx, ny) not in st:
                    st.add((nx, ny))
                    if 剑雨(nx, ny):
                        Q.append([nx, ny, 1, 0])
                    else:
                        Q.append([nx, ny, 0, 0])
        else:
            Q.append([x, y, 0, 0])
            
    for _ in range(II()):
        a, b = II(), II()
        ans = 0
        for x in Q:
            if x[3] == 1:
                continue
            if 矩形(a, b, x[0], x[1]):
                x[3] = 1
                if x[2] == 1:
                    ans += 669 * 4
                else:
                    ans += 669 * 2
        out.append(ans)

main()

print('\n'.join(map(str, out)))