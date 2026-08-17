from collections import Counter
import sys
input = lambda: sys.stdin.readline().strip()
#it = iter(sys.stdin.read().split())
#SI = lambda: next(it)
#II = lambda: int(SI())

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    a = list(input().split(','))
    mp = Counter()
    for x in a:
        t = x.split(':')
        mp[t[0]] += int(t[1])  
    mx = max(mp.values())
    ans = 'xjs'
    for x, y in mp.items():
        if y == mx:
            if ans == 'xjs':
                ans = x
            ans = min(ans, x)
    out.append(f'{len(mp)}\n{ans}')

main()

print('\n'.join(map(str, out)))
