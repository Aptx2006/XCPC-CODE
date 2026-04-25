import sys, math
input = lambda: sys.stdin.readline().strip()

h, w = map(int, input().split())
s = [input() for _ in range(h)]
def isok(G, h1, h2, w1, w2):
	for i in range(h1, h2 + 1):
		for j in range(w1, w2 + 1):
			ni = h1 + h2 - i
			nj = w1 + w2 - j
			if G[i][j] != G[ni][nj]:
				return False
	return True
ans = 0
for h1 in range(h):
    for h2 in range(h1, h):
        for w1 in range(w):
            for w2 in range(w1, w):
                if isok(s, h1, h2, w1, w2):
                    ans += 1

print(ans)