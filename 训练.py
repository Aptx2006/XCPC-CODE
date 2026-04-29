class FenwickTree:
    def __init__(self, size):
        self.n = size
        self.t = [float('-inf')] * (self.n + 2)
    def update(self, i, v):
        while i <= self.n:
            self.t[i] = max(self.t[i], v)
            i += i & -i
    def query(self, i):
        res = float('-inf')
        while i > 0:
            res = max(res, self.t[i])
            i -= i & -i
        return res

class Solution:
    def maxAlternatingSum(self, nums: list[int], k: int) -> int:
        n = len(nums)
        mx = max(nums)
        INF = -10**19
        up = [INF] * n
        down = [INF] * n

        upfwt = FenwickTree(mx + 2)
        lessUp = FenwickTree(mx + 2)

        ans = 0
        for i in range(n):
            if i - k >= 0:
                j = i - k
                v = nums[j]
                upfwt.update(v, max(down[j], v))
                lessUp.update(mx - v + 1, max(up[j], v))
            v = nums[i]
            up[i] = v
            down[i] = v
            bestSmall = upfwt.query(v - 1)
            if bestSmall != INF:
                up[i] = max(up[i], bestSmall + v)
            bestLarge = lessUp.query(mx - v)
            if bestLarge != INF:
                down[i] = max(down[i], bestLarge + v)
            ans = max(ans, up[i], down[i])
        return ans
