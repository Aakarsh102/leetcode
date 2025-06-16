class Solution:
    def countSubstrings(self, s: str) -> int:
        count = 0
        i = 0
        while i < len(s):
            start = i
            end = i
            while (start >= 0 and end < len(s)):
                if (s[start] == s[end]):
                    count += 1
                    start -= 1
                    end += 1
                else:
                    break
            start = i
            end = i + 1
            while (start >= 0 and end < len(s)):
                if (s[start] == s[end]):
                    count += 1
                    start -= 1
                    end += 1
                else:
                    break
            i += 1

        return count