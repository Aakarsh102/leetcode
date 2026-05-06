class Solution:
    def lengthOfLongestSubstringTwoDistinct(self, s: str) -> int:
        lo = {}
        l = 0
        r = 0
        n = len(s)
        if (n <= 2):
            return n
        max_size = 0
        while (r < n):
            if s[r] in lo:
                lo[s[r]] = r
            else:
                if len(lo) == 2:
                    l = self.shift(lo)
                lo[s[r]] = r
                
            max_size = max(max_size, r - l + 1)
            r += 1
        return max_size
        
                
    def shift(self, lo):
        minimum = 1000000
        k = -1
        for key, value in lo.items():
            if (minimum > value):
                k = key 
                minimum = value 
        l = minimum + 1
        lo.pop(k)
        return l
