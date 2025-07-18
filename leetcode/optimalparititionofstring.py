class Solution:
    def partitionString(self, s: str) -> int:
        seen = set()
        count = 1
        for i in s:
            if i in seen:
                count += 1
                seen = {i}
            else: 
                seen.add(i)

        return count