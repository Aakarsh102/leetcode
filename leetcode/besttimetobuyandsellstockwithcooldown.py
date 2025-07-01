class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        profit = 0
        dp = {}
        def dper(index, buy):
            if index >= len(prices):
                return 0
            if (dp.get((index, buy), -1) != -1):
                return dp[(index, buy)]
            if buy:
                a = dper(index + 1, not buy) - prices[index]
                b = dper(index + 1, buy)
                profit = max(a, b)
                dp[(index, buy)] = profit
            else: 
                a = dper(index + 2, not buy) + prices[index]
                b = dper(index + 1, buy)
                profit = max(a, b)
                dp[(index, buy)] = profit
            return profit
        return dper(0, True)