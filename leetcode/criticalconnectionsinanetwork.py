from typing import List
class Solution:
    def criticalConnections(self, n: int, connections: List[List[int]]) -> List[List[int]]:
        adj_list = [[] for i in range(n)]
        for con in connections:
            adj_list[con[0]].append(con[1])
            adj_list[con[1]].append(con[0])

        disc = [-1] * n
        low = [-1] * n
        result = []
        time = -1

        def dfs_tarjan(cur, parent):
            nonlocal time
            time += 1
            disc[cur] = low[cur] = time

            for to in adj_list[cur]:
                if to == parent:
                    continue
                if (disc[to] != -1): 
                    low[cur] = min(low[cur], low[to])
                    continue
                dfs_tarjan(to, cur)
                low[cur] = min(low[cur], low[to])
                if low[to] > disc[cur]:
                    result.append([cur, to])
                
        dfs_tarjan(0, -1)
        return result
