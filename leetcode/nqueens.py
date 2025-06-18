class Solution:
    def solveNQueens(self, n: int) -> list[list[str]]:
        solutions = []
        cols = set()       # occupied columns
        diag1 = set()      # occupied “\” diagonals, key = row+col
        diag2 = set()      # occupied “/” diagonals, key = row−col
        board = []         # list of column indices for each row

        def do_backtrack(index):
            if index == n:
                solutions.append(locs_to_output())
                return
            for col in range( n):
                if (col in cols or (col - index) in diag2 or (col + index) in diag1):
                    continue
                cols.add(col)
                diag1.add(col + index)
                diag2.add(col - index)
                board.append(col)
                do_backtrack(index + 1)
                board.pop()
                diag2.remove(col - index)
                diag1.remove(col + index)
                cols.remove(col)
            
        def locs_to_output():
            k = []
            for i in board:
                k.append("." * i + "Q" + "." * (n - i - 1))
            return k

        do_backtrack(0)
        return solutions
        