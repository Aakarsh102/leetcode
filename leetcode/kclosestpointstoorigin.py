import heapq
class Solution:
    def kClosest(self, points: list[list[int]], k: int) -> list[list[int]]:
        heap = []
        for i, (x, y) in enumerate(points):
            dist = -(x**2 + y**2)  # negative for max heap
            if len(heap) < k:
                heapq.heappush(heap, (dist, i))
            else:
                if dist > heap[0][0]:  # closer than the farthest in heap
                    heapq.heappop(heap)
                    heapq.heappush(heap, (dist, i))
        return [points[i] for _, i in heap]
        