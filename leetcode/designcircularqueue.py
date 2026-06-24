class MyCircularQueue:

    def __init__(self, k: int):
        self.q = [-1] * k
        self.head = 0
        self.tail = 0
        self.size = k

    def enQueue(self, value: int) -> bool:
        if (self.q[self.tail] != -1):
            return False
        self.q[self.tail] = value
        self.tail = (self.tail + 1) % self.size
        return True

    def deQueue(self) -> bool:
        if (self.q[self.head] == -1):
            return False
        self.q[self.head] = -1
        self.head = (self.head + 1) % self.size
        return True

    def Front(self) -> int:
        return self.q[self.head]

    def Rear(self) -> int:
        return self.q[(self.tail - 1) % self.size]

    def isEmpty(self) -> bool:
        if self.head == self.tail and self.q[self.head] == -1:
            return True
        return False

    def isFull(self) -> bool:
        if self.head == self.tail and self.q[self.head] != -1:
            return True
        return False


# Your MyCircularQueue object will be instantiated and called as such:
# obj = MyCircularQueue(k)
# param_1 = obj.enQueue(value)
# param_2 = obj.deQueue()
# param_3 = obj.Front()
# param_4 = obj.Rear()
# param_5 = obj.isEmpty()
# param_6 = obj.isFull()