class Solution:
    def pacificAtlantic(self, heights: list[list[int]]) -> list[list[int]]:
        m = len(heights)
        n = len(heights[0])
        pacific = [[False for i in range(n)] for j in range(m)]
        atlantic = [[False for i in range(n)] for j in range(m)]
        stack = []
        
        for k in range(m):
            stack.append([k,0])
            while(not len(stack) == 0):
                l = stack.pop()
                i, j = l[0],l[1]
                pacific[i][j] = True
                if i < m - 1:
                    if (heights[i + 1][j] >= heights[i][j] and not pacific[i+1][j]):
                        stack.append([i + 1, j])
                if i > 0:
                    if heights[i - 1][j] >= heights[i][j] and not pacific[i-1][j]:
                        stack.append([i - 1, j])
                if j < n - 1:
                    if heights[i][j + 1] >= heights[i][j] and not pacific[i][j+1]:
                        stack.append([i, j + 1])
                if j > 0:
                    if heights[i][j - 1] >= heights[i][j] and not pacific[i][j-1]:
                        stack.append([i, j - 1])
        for k in range(n):
            stack.append([0,k])
            while(not len(stack) == 0):
                l = stack.pop()
                i, j = l[0],l[1]
                pacific[i][j] = True
                if i < m - 1:
                    if (heights[i + 1][j] >= heights[i][j] and not pacific[i+1][j]):
                        stack.append([i + 1, j])
                if i > 0:
                    if heights[i - 1][j] >= heights[i][j] and not pacific[i-1][j]:
                        stack.append([i - 1, j])
                if j < n - 1:
                    if heights[i][j + 1] >= heights[i][j] and not pacific[i][j+1]:
                        stack.append([i, j + 1])
                if j > 0:
                    if heights[i][j - 1] >= heights[i][j] and not pacific[i][j-1]:
                        stack.append([i, j - 1])
        for k in range(m):
            stack.append([m-k-1,n-1])
            while not len(stack) == 0:
                l = stack.pop()
                i, j = l[0],l[1]
                atlantic[i][j] = True
                if i < m - 1:
                    if (heights[i + 1][j] >= heights[i][j] and not atlantic[i+1][j]):
                        stack.append([i + 1, j])
                if i > 0:
                    if heights[i - 1][j] >= heights[i][j] and not atlantic[i-1][j]:
                        stack.append([i - 1, j])
                if j < n - 1:
                    if heights[i][j + 1] >= heights[i][j] and not atlantic[i][j+1]:
                        stack.append([i, j + 1])
                if j > 0:
                    if heights[i][j - 1] >= heights[i][j] and not atlantic[i][j-1]:
                        stack.append([i, j - 1])
        for k in range(n):
            stack.append([m-1,n-1 - k])
            while not len(stack) == 0:
                l = stack.pop()
                i, j = l[0],l[1]
                atlantic[i][j] = True
                if i < m - 1:
                    if (heights[i + 1][j] >= heights[i][j] and not atlantic[i+1][j]):
                        stack.append([i + 1, j])
                if i > 0:
                    if heights[i - 1][j] >= heights[i][j] and not atlantic[i-1][j]:
                        stack.append([i - 1, j])
                if j < n - 1:
                    if heights[i][j + 1] >= heights[i][j] and not atlantic[i][j+1]:
                        stack.append([i, j + 1])
                if j > 0:
                    if heights[i][j - 1] >= heights[i][j] and not atlantic[i][j-1]:
                        stack.append([i, j - 1])
        res = []
        for i in range(m):
            for j in range(n):
                if atlantic[i][j] == True and pacific[i][j] == True:
                    res.append([i,j])
        return res



