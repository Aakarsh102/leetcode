from typing import List
from collections import defaultdict

class Solution:
    def restoreArray(self, adjacentPairs: List[List[int]]) -> List[int]:
        n = len(adjacentPairs)
        adj_list = defaultdict(list)
        
        for a,b in adjacentPairs:
            adj_list[a].append(b)
            adj_list[b].append(a)
        ends = []
        for i in adj_list.keys():
            if len(adj_list[i]) == 1:
                ends.append(i)

        ret = [ends[0]]
        visited = {ends[0]}
        cur = ends[0]
        while cur != ends[1]:
            if adj_list[cur][0] not in visited:
                ret.append(adj_list[cur][0])
                visited.add(adj_list[cur][0])
            else:
                ret.append(adj_list[cur][1])
                visited.add(adj_list[cur][1])
            cur = ret[-1]

        return list(ret)
            
            
