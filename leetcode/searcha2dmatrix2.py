class Solution:
    def searchMatrix(self, matrix: list[list[int]], target: int) -> bool:

        i = 0
        j = len(matrix[0]) - 1
        while (j >= 0 and i < len(matrix)):
            if matrix[i][j] == target:
                return True
            if matrix[i][j] > target:
                j -= 1
            else:
                i += 1
        return False
                

        
        