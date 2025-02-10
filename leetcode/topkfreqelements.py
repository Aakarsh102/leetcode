class Solution:
    def topKFrequent(self, nums: list[int], k: int) -> list[int]:
        old_k = {}

        for i in nums:
            old_k[i] = old_k.get(i, 0) + 1
        # for key,value in old_k.items():

        ret = []
        for i in range(k):
            key = max(old_k, key=old_k.get)
            ret.append(key)
            old_k.pop(key)
        return ret
