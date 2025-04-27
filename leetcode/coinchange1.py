class Solution:
    def coinChange(self, coins: list[int], amount: int) -> int:
        large = amount + 1
        dp = [large for i in range(amount + 1)] 
        dp[0] = 0

        for i in range(1, amount + 1):
            for coin in coins:
                if coin <= i:
                    dp[i] = min(dp[i], dp[i - coin] + 1)

        if dp[amount] != large:
            return dp[amount]
        return -1