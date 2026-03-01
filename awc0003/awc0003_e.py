import sys
input = lambda: sys.stdin.readline()
def main():
    n, m = map(int, input().split())
    w = list(map(int, input().split()))
    c = list(map(int, input().split()))
    
    w.sort(reverse=True)
    c.sort(reverse=True)
    a = [0] * m 
    
    def dfs(i):
        if i == n:
            return True  
        for j in range(m):
            if a[j] + w[i] > c[j]:
                continue
            if j > 0 and c[j] == c[j-1] and a[j] == a[j-1]:
                continue
            a[j] += w[i]
            if dfs(i + 1):
                return True
            a[j] -= w[i]
            if a[j] == 0:
                break
        return False
    
    if dfs(0):
        print("Yes")
    else:
        print("No")

main()