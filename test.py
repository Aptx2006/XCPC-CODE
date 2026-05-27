def get_S(n, edges):
    from collections import defaultdict
    adj = defaultdict(list)
    for u, v in edges:
        adj[u].append(v)
        adj[v].append(u)

    memo = {}
    def dfs(nodes):
        nodes_tuple = tuple(sorted(nodes))
        if len(nodes) <= 1:
            return {tuple()}
        if nodes_tuple in memo:
            return memo[nodes_tuple]
            
        leaves = [node for node in nodes if sum(1 for v in adj[node] if v in nodes) <= 1]
        max_leaf = max(leaves)
        res = set()
        for l in leaves:
            sub_res = dfs([u for u in nodes if u != l])
            for s in sub_res:
                res.add( (max_leaf,) + s )
        memo[nodes_tuple] = res
        return res
        
    return dfs(list(range(1, n+1)))

print('Star graph 4:')
print(len(get_S(4, [(4, 1), (4, 2), (4, 3)])))

print('Path graph 4:')
print(len(get_S(4, [(1,2), (2,3), (3,4)])))

print('Tree 1 (6 nodes):')
edges = [(1,4), (2,4), (3,4), (4,5), (5,6)]
print(len(get_S(6, edges)))
