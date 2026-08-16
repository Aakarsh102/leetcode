from collections import defaultdict

class Solution:
    def minSetSize(self, arr: list[int]) -> int:
        d = defaultdict(int)
        for i in arr:
            d[i] += 1
        
        l = [v for v in d.values()]
        l.sort(reverse = True)
        total = len(arr) // 2
        s = 0
        i = 0
       
        while s < total:
            s += l[i]
            i += 1
        return i


            