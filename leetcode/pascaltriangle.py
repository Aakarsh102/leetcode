class Solution:
    def generate(self, numRows: int) -> list[list[int]]:
        if (numRows == 1):
            return [[1]]
        elif (numRows == 2):
            return [[1], [1,1]]
        
        res = [[1 for _ in range(i)] for i in range(1, numRows+1)]
        i = 2
        j = 0
        while (i < numRows + 1) :
            j = 1
            while (j < len(res[i - 2])):
                res[i-1][j] = res[i-2][j-1] + res[i-2][j]
                j += 1
            i += 1

        return res

        
