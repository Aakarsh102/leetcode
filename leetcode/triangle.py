class Solution:
    def minimumTotal(self, triangle: list[list[int]]) -> int:
        dp = [[0 for _ in range(i)] for i in range(1, len(triangle) + 1)]
        dp[0][0] = triangle[0][0]
        for i in range(1, len(triangle)):
            for j in range(len(triangle[i])):
                index_1 = j - 1 if j - 1 >= 0 else 0
                index_2 = j if j < len(triangle[i-1]) else len(triangle[i-1]) - 1
                dp[i][j] = min(dp[i-1][index_1] + triangle[i][j], dp[i-1][index_2] + triangle[i][j])
        return min(dp[len(triangle) - 1])
