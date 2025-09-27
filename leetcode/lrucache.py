from collections import OrderedDict
class LRUCache:
    def __init__(self, capacity: int):
        self.capcity = capacity
        self.dic = OrderedDict()

    def get(self, key: int) -> int:
        if(self.dic.get(key, -1) == -1):
            return -1
        self.dic.move_to_end(key)
        return self.dic[key]

    def put(self, key: int, value: int) -> None:
        if (self.dic.get(key, -1) == -1 and len(self.dic) == self.capcity):
            # self.dic.pop(list(self.dic.keys())[0])
            self.dic.popitem(last = False)
        self.dic[key] = value
        self.dic.move_to_end(key)

# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)