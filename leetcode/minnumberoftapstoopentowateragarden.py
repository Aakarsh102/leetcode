class Solution:
    def minTaps(self, n: int, ranges: list[int]) -> int:
        intervals = [[i - ranges[i], i + ranges[i]] for i in range(len(ranges))]
        intervals.sort(key= lambda x: x[0])
        start = 0
        end = 0
        i = 0
        count = 0
        while end < n:
            max_end = end
            cur = intervals[i] 
            while (end >= cur[0]):
                if cur[1] > max_end:
                    max_end = cur[1]
                i += 1
                if (i > n):
                    break
    
                cur = intervals[i] 
            if max_end > end:
                count += 1
                end = max_end
            else:
                return -1
        return count


        
        
# [1,2,3,4,5,0,4,0,3,0,2,0,1]
