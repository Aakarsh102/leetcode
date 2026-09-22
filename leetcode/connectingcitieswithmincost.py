import heapq
class Solution:
    def minimumCost(self, n: int, connections: list[list[int]]) -> int:
        for i in connections:
            i.reverse()

        heap = []
        for i in connections:
            heapq.heappush(heap, i)
        
        s = [i for i in range(1, n + 1)]
        def find(a):
            if (s[a - 1] == a):
                return a
            s[a - 1] = find(s[a - 1])
            return s[a - 1]
        total = 0
        while heap:
            cur = heapq.heappop(heap)
            a = find(cur[1])
            b = find(cur[2])
            if a != b:
                s[a - 1] = b
                total += cur[0]
        l = find(s[0])
        for i in range(1, n):
            if l != find(s[i]):
                return -1
        return total
            


        
