class Solution:
    def numSquares(self, n: int) -> int:
        if n==1:return 1
        if n==2:return 2
        if n==3:return 3
        root = int(n ** 0.5) + 1
        # if (root - 1 == n**0.5):
        #     return 1
        roots = []
        for i in range(root):
            roots.append(i**2)
        counts = [n + 1 for i in range(n + 1)]

        counts[1] = 1
        counts[2] = 2
        for i in roots:
            counts[i] = 1
        counts[0] = 0
        for i in range(3, n + 1):
            m = n + 1
            # for j in range(0, i):
            #     m = min(counts[j] + counts[i - j], m)
            for j in roots:
                if j > i: continue
                m = min(counts[j] + counts[i - j],m)
            counts[i] = m
        # print(counts)
        return counts[n]
        