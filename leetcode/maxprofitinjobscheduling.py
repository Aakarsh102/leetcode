from bisect import bisect_right

class Solution:
    def jobScheduling(self, startTime: List[int], endTime: List[int], profit: List[int]) -> int:
        
        zipped = list(zip(startTime, endTime, profit))
        zipped.sort(key = lambda k : k[1])
        endTime.sort()
        dp_arr = [zipped[0][2]]
        
        for i in range(1, len(zipped)): 
            last_id = bisect_right(endTime, zipped[i][0])
            if (last_id == 0):
                dp_arr.append(max(dp_arr[i-1],zipped[i][2]))
            else:
                dp_arr.append(max(dp_arr[i-1], dp_arr[last_id - 1] + zipped[i][2]))
            

        return dp_arr[-1]


        