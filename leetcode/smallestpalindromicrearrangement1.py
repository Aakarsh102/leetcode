class Solution:
    def smallestPalindrome(self, s: str) -> str:
        
        n = len(s)
        if (n == 1):
            return s
        mid = n >> 1 
        l = s[:mid]
        l = list(l)
        l.sort()
        m = ""
        if n & 1 == 1:
            m = s[mid]
        final_str = "".join(l) + m + "".join(reversed(l))
        return final_str