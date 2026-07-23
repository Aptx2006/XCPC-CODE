import sys
from itertools import combinations 
input = lambda: sys.stdin.readline().strip()
# it = map(int, sys.stdin.read().split())
# II = lambda: next(it)

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []


def main():
    n, a, b = map(int, input().split())
    s = int(input())
    mp = {}
    for _ in range(s):
        t, p, v = input().split()
        t = int(t)

        if p not in mp:
            mp[p] = {'ac': False, 'wa': 0, 'cost': -1}
            
        if mp[p]['ac']:
            continue
            
        if v == 'ac':
            mp[p]['ac'] = True
            mp[p]['time'] = t + 20 * mp[p]['wa']
        elif v == 'rj':
            mp[p]['wa'] += 1
        elif v == 'pd' and mp[p]['cost'] == -1:
            mp[p]['cost'] = t + 20 * mp[p]['wa']
            
    ac = sum(1 for st in mp.values() if st['ac'])
    time = sum(st['time'] for st in mp.values() if st['ac'])
    best = sorted([st['cost'] for st in mp.values() if not st['ac'] and st['cost'] != -1])
    
    ans = -1
    for k in range(len(best) + 1):
        ac_ = ac + k
        if k > 0:
            time += best[k-1]
        if ac_ > a or (ac_ == a and time < b):
            ans = k
            break
            
    out.append(ans)
        

for _ in range(int(input())):
    main()

print('\n'.join(map(str, out)))
