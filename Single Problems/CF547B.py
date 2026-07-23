import sys
input = lambda: sys.stdin.readline().strip()
it = iter(sys.stdin.read().split())
SI = lambda: next(it)
II = lambda: int(SI())


fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    n = II()
    nums = [II() for _ in range(n)]

    left = [-1] * n
    st = []
    for i, x in enumerate(nums):
        while st and nums[st[-1]] >= x:
            st.pop()
        if st:
            left[i] = st[-1]
        st.append(i)

    st = []
    right = [n] * n
    for i, x in enumerate(nums[::-1]):
        j = n - i - 1
        while st and nums[st[-1]] >= x:
            st.pop()
        if st:
            right[j] = st[-1]
        st.append(j)

    ans = [0] * (n + 2)  
    for i in range(n):
        len = right[i] - left[i] - 1   
        ans[len] = max(ans[len], nums[i])
    
    for i in range(n - 1, 0, -1):
        ans[i] = max(ans[i], ans[i + 1])
    
    for i in range(1, n + 1):
        out.append(ans[i])


main()

print(' '.join(map(str, out)))
