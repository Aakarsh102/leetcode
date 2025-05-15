class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        di = {0: [0 for i in range(9)], 1: [0 for i in range(9)], 2: [0 for i in range(9)], 3: [0 for i in range(9)], 4: [0 for i in range(9)], 5: [0 for i in range(9)], 6: [0 for i in range(9)], 7: [0 for i in range(9)], 8: [0 for i in range(9)]}
        r = {0: [0 for i in range(9)], 1: [0 for i in range(9)], 2: [0 for i in range(9)], 3: [0 for i in range(9)], 4: [0 for i in range(9)], 5: [0 for i in range(9)], 6: [0 for i in range(9)], 7: [0 for i in range(9)], 8: [0 for i in range(9)]}
        c = {0: [0 for i in range(9)], 1: [0 for i in range(9)], 2: [0 for i in range(9)], 3: [0 for i in range(9)], 4: [0 for i in range(9)], 5: [0 for i in range(9)], 6: [0 for i in range(9)], 7: [0 for i in range(9)], 8: [0 for i in range(9)]}
        for i in range(9):
            for j in range(9):
                box_cor = int(i/3) * 3 + int(j/3)
                if (board[i][j] == '.'):
                    continue
                if (di[box_cor][int(board[i][j]) - 1] == 1):
                    return False
                else:
                    di[box_cor][int(board[i][j]) - 1] = 1
                if (r[i][int(board[i][j]) - 1] == 1):
                    return False
                else:
                    r[i][int(board[i][j]) - 1] = 1
                if (c[j][int(board[i][j]) - 1] == 1):
                    return False
                else:
                    c[j][int(board[i][j]) - 1] = 1
                

        return True    
        