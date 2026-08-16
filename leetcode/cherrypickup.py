class Solution:
    def cherryPickup(self, grid: list[list[int]]) -> int:
        n = len(grid)
        dp = [[-1000] * (n + 1) for _ in range(n + 1)]
        dp[1][1] = grid[0][0]
        best = 0
        for step in range(1, 2 * (n - 1) + 1):
            new_dp = [[-1000] * (n + 1) for _ in range(n + 1)]
            for r1 in range(1, n + 1):
                row1 = r1 - 1
                c1 = step - row1
                if c1 < 0:
                    break
                if c1 >= n:
                    continue
                for r2 in range(1, n + 1):
                    row2 = r2 - 1
                    c2 = step - row2
                    if c2 < 0:
                        break
                    if c2 >=n or grid[row2][c2] == -1 or grid[row1][c1] == -1:
                        new_dp[r1][r2] = -10000
                        continue
                    m = max(dp[r1][r2], dp[r1 - 1][r2 - 1], dp[r1][r2 - 1], dp[r1 - 1][r2])
                    if (r1 != r2 and grid[row1][c1] == 1 and grid[row2][c2] == 1):
                        m += 2
                    elif (grid[row1][c1] == 1 or grid[row2][c2] == 1):
                        m += 1
                    new_dp[r1][r2] = m
                    # print('a:', row1, c1, row2, c2)
                    # print(new_dp)
            dp = new_dp 
        return max(dp[n][n], 0)



        