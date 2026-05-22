import heapq
class Solution:
    def getNumberOfBacklogOrders(self, orders):
        MOD = 10**9 + 7

        buy = []   
        sell = []  
        for price, amount, orderType in orders:

            if orderType == 0:

                while amount > 0 and sell and sell[0][0] <= price:
                    sell_price, sell_amount = heapq.heappop(sell)

                    matched = min(amount, sell_amount)

                    amount -= matched
                    sell_amount -= matched

                    if sell_amount > 0:
                        heapq.heappush(sell, (sell_price, sell_amount))
                        break

                if amount > 0:
                    heapq.heappush(buy, (-price, amount))

            else:

                while amount > 0 and buy and -buy[0][0] >= price:
                    buy_price, buy_amount = heapq.heappop(buy)

                    matched = min(amount, buy_amount)

                    amount -= matched
                    buy_amount -= matched

                    if buy_amount > 0:
                        heapq.heappush(buy, (buy_price, buy_amount))
                        break

                if amount > 0:
                    heapq.heappush(sell, (price, amount))
                    

        ans = 0

        for _, amount in buy:
            ans = (ans + amount) % MOD

        for _, amount in sell:
            ans = (ans + amount) % MOD

        return ans