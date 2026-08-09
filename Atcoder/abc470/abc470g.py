import sys

def main():
    # 使用 sys.stdin.read() 实现最快 I/O 读取
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    N = int(input_data[0])
    
    # 线段树覆盖的范围是 [0, N]，即 N+1 个叶子节点
    N_max = N
    size = 4 * N_max + 100
    
    # 线段树所需的一维数组（使用全局一维数组比类更高效）
    min_val = [0] * size
    sum_pref = [0] * size
    
    # 手动维护迭代路径，避免递归开销
    path_nodes = [0] * 64
    path_Ls = [0] * 64
    path_Rs = [0] * 64
    
    total_ans = 0
    
    for r in range(1, N + 1):
        idx = int(input_data[r])
        if idx > N_max:
            idx = N_max  # 安全防越界，实际根据题意 A_i <= N
            
        node = 1
        L = 0
        R = N_max
        depth = 0
        
        # 1. 向下查找到叶子节点，并记录路径
        while L < R:
            path_nodes[depth] = node
            path_Ls[depth] = L
            path_Rs[depth] = R
            depth += 1
            
            mid = (L + R) // 2
            if idx <= mid:
                node = 2 * node
                R = mid
            else:
                node = 2 * node + 1
                L = mid + 1
                
        # 更新叶子节点 (相当于让 pos[A_r] = r)
        min_val[node] = r
        sum_pref[node] = r
        
        # 2. 自底向上无递归 pushup (更新线段树节点状态)
        for i in range(depth - 1, -1, -1):
            p_node = path_nodes[i]
            p_L = path_Ls[i]
            p_R = path_Rs[i]
            
            left_child = 2 * p_node
            right_child = left_child + 1
            
            m_left = min_val[left_child]
            m_right = min_val[right_child]
            min_val[p_node] = m_left if m_left < m_right else m_right
            
            # --- 以下是计算右子树在前缀最小值为 m_left 时的新贡献度 ---
            c_node = right_child
            c_L = ((p_L + p_R) // 2) + 1
            c_R = p_R
            v = m_left
            
            res = 0
            while c_L < c_R:
                c_mid = (c_L + c_R) // 2
                c_left = 2 * c_node
                m_c_left = min_val[c_left]
                
                if v <= m_c_left:
                    # 如果传进来的 v 比左半边最小值还小，整个左半边的前缀最小值都会被钳制为 v
                    res += v * (c_mid - c_L + 1)
                    # 只有右半边可能会有小于 v 的突破，继续向右探测
                    c_node = c_left + 1
                    c_L = c_mid + 1
                else:
                    # 如果 v 大于左半边最小值，那 v 的钳制在左半边就会失效，右半边直接沿用之前算好的 sum_pref 变化差量
                    res += sum_pref[c_node] - sum_pref[c_left]
                    # 继续向左探测 v 的钳制衰减点
                    c_node = c_left
                    c_R = c_mid
                    
            # 抵达最终叶子的单点结算
            res += v if v < min_val[c_node] else min_val[c_node]
            
            # 结算当前树根真正的 sum_pref
            sum_pref[p_node] = sum_pref[left_child] + res
            
        # 3. 根节点的 sum_pref 即为当前由 r 为右端点的所有合法区间 mex 总和
        total_ans += sum_pref[1]
        
    print(total_ans)

if __name__ == '__main__':
    main()