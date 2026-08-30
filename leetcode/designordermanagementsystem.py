from collections import defaultdict
from typing import List

class OrderManagementSystem:

    def __init__(self):
        self.sell_orders = defaultdict(list)
        self.buy_orders = defaultdict(list)
        self.order_to_price = {}


    def addOrder(self, orderId: int, orderType: str, price: int) -> None:
        if orderType == "sell":
            self.sell_orders[price].append(orderId)
            i = len(self.sell_orders[price]) - 1
        else:
            self.buy_orders[price].append(orderId)
            i = len(self.buy_orders[price]) - 1
        self.order_to_price[orderId] = [price, orderType, i]

    def modifyOrder(self, orderId: int, newPrice: int) -> None:
        p, t, i = self.order_to_price[orderId]
        self.order_to_price[orderId] = [newPrice, t]
        if t == "sell":
            self.sell_orders[p][i] = -1
            self.sell_orders[newPrice].append(orderId)
            i = len(self.sell_orders[newPrice]) - 1
        else:
            self.buy_orders[p][i] = -1
            self.buy_orders[newPrice].append(orderId)
            i = len(self.buy_orders[newPrice]) - 1
        self.order_to_price[orderId] = [newPrice, t, i]

        


    def cancelOrder(self, orderId: int) -> None:
        p, t, i = self.order_to_price[orderId]
        del self.order_to_price[orderId]
        if t == "sell":
            self.sell_orders[p][i] = -1
        else:
            self.buy_orders[p][i] = -1
        

    def getOrdersAtPrice(self, orderType: str, price: int) -> List[int]:
        l = []
        if orderType == 'sell':
            for i in self.sell_orders[price]:
                if i == -1:
                    continue
                l.append(i)
        else:
            for i in self.buy_orders[price]:
                if i == -1:
                    continue
                l.append(i)

        return l
        


# Your OrderManagementSystem object will be instantiated and called as such:
# obj = OrderManagementSystem()
# obj.addOrder(orderId,orderType,price)
# obj.modifyOrder(orderId,newPrice)
# obj.cancelOrder(orderId)
# param_4 = obj.getOrdersAtPrice(orderType,price)