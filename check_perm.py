from itertools import permutations
import random

def f(arr):
    n=len(arr)
    cnt=0
    for l in range(n):
        prod=1
        for r in range(l,n):
            prod*=arr[r]
            if prod%6==0:
                cnt+=1
    return cnt


def best_perm(arr):
    best=10**9
    bestp=None
    for p in permutations(arr):
        val=f(list(p))
        if val<best:
            best=val
            bestp=list(p)
    return best,bestp


def type_map(x):
    a = (x%2==0)
    b = (x%3==0)
    if a and b: return '6'
    if a: return '2'
    if b: return '3'
    return '0'

# test many random arrays
for _ in range(200):
    n=random.randint(1,7)
    arr=[random.randint(1,20) for _ in range(n)]
    best,bestp=best_perm(arr)
    # greedy grouping tried: 0,2,6,3
    order=[]
    for x in arr:
        if type_map(x)=='0': order.append(x)
    for x in arr:
        if type_map(x)=='2': order.append(x)
    for x in arr:
        if type_map(x)=='6': order.append(x)
    for x in arr:
        if type_map(x)=='3': order.append(x)
    g=f(order)
    if g!=best:
        print('Found counterexample')
        print('arr',arr)
        print('best',best,'perm',bestp,'types',''.join(type_map(x) for x in bestp))
        print('greedy',order,'g',g,'types',''.join(type_map(x) for x in order))
        break
else:
    print('No counterexample found in 200 trials')
