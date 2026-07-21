n=int(input())
a=list(map(int,input().split()))
ans=0
for i in range(n):
    ans=ans-(n-1-i)*a[i]
    ans=ans+(i*a[i])
print(ans)