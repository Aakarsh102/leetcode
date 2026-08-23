import math
class Solution:
    def countDifferentSubsequenceGCDs(self, nums: list[int]) -> int:
        hs = set(nums)
        count = 1
        max_val = max(hs)
        
        for d in range(1, max_val):
            cur_gcd = 0
            for elem in range(d, max_val+1, d):
                if elem in hs:
                    k = math.gcd(cur_gcd, elem)
                    if k == d:
                        count += 1
                        break
                    cur_gcd = k 
                    
        return count
            
                        
                    