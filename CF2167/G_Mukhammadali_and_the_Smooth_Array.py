import sys,math
input = lambda:sys.stdin.read().strip()
text = input().split()
P = 0
T = int(text[P])
P += 1
for _ in range(T):
    n = int(text[P])
    a = list(map(int, text[P+1:P+1+n]))
    P += n+1
    c = list(map(int, text[P:P+n]))
    P += n
    dp = [0]*(n+1)
    #print("n={}".format(n))
    for i in range(1,n+1):
        dp[i] = int(c[i-1])
        for j in range(1,i):
            if(a[j-1]>a[i-1]):
                continue
            dp[i] = max(dp[i],dp[j]+c[i-1])
    print(sum(c)-max(dp))
