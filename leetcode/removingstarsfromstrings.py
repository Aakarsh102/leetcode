class Solution:
    def removeStars(self, s: str) -> str:
        l = []
        i = 0
        while i < len(s):
            if s[i] == '*':
                l.pop()
            else:
                l.append(s[i])
            i += 1
        return "".join(l)