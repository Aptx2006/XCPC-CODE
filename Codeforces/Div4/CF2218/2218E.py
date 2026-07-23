import sys
it = map(int, sys.stdin.buffer.read().split())
II = lambda: next(it)
from array import array

def DT(nums):
    if len(nums) < 2:
        return 0

    mx = max(nums).bit_length() - 1
    if mx < 0:
        return 0

    ch0 = array("i", [-1])
    ch1 = array("i", [-1])

    def new_node():
        ch0.append(-1)
        ch1.append(-1)
        return len(ch0) - 1

    def insert(x):
        p = 0
        for k in range(mx, -1, -1):
            b = (x >> k) & 1
            if b == 0:
                nxt = ch0[p]
                if nxt == -1:
                    nxt = new_node()
                    ch0[p] = nxt
                p = nxt
            else:
                nxt = ch1[p]
                if nxt == -1:
                    nxt = new_node()
                    ch1[p] = nxt
                p = nxt

    def query(x):
        p = 0
        res = 0
        for k in range(mx, -1, -1):
            b = (x >> k) & 1
            if b == 0:
                nxt = ch1[p]
                if nxt != -1:
                    res |= 1 << k
                    p = nxt
                else:
                    p = ch0[p]
            else:
                nxt = ch0[p]
                if nxt != -1:
                    res |= 1 << k
                    p = nxt
                else:
                    p = ch1[p]
        return res

    ans = 0
    insert(nums[0])
    for x in nums[1:]:
        cur = query(x)
        if cur > ans:
            ans = cur
        insert(x)
    return ans


def solve():
    n = II()
    a = [II() for _ in range(n)]
    print((DT(a)))

for _ in range(II()):
    solve()
