class Solution:
    def setZeroes(self, matrix: list[list[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        rows = []
        cols = []
        m = len(matrix)
        n = len(matrix[0])
        for i in range(m):
            for j in range(n):
                if (matrix[i][j] == 0):
                    rows.append(i)
                    cols.append(j)
        for i in rows:
            for j in range(n):
                matrix[i][j] = 0
        for j in cols:
            for i in range(m):
                matrix[i][j] = 0
        