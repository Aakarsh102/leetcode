import heapq
class Solution:
    def lastStoneWeight(self, stones:list[int]) -> int:
        for i in range(len(stones)):
            stones[i] = -stones[i]

        heapq.heapify(stones)
        while (len(stones) > 1):
            n = heapq.heappop(stones) - heapq.heappop(stones)
            if (n != 0):
                heapq.heappush(stones, n)
        if (len(stones) == 0):
            return 0
        return -stones[0]

