class Solution:
    def partition(self, s: str) -> list[list[str]]:
        i = 0
        j = 0
        res = []
        partitions = []
        count = 0
        def do_backtrack(index):
            if index == len(s):
                res.append(partitions.copy())
                return
            for i in range(index, len(s)):
                if check_pal(index, i):
                    partitions.append(s[index:i+1])
                    do_backtrack(i + 1)
                    partitions.pop()

        def check_pal(i, j):
            while (i < j):
                if s[i] != s[j]:
                    return False 
                i += 1
                j -= 1
            return True

        do_backtrack(0)
        return res
