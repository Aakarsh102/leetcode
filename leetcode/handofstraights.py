import collections
from collections import Counter
class Solution:
    def isNStraightHand(self, hand: list[int], groupSize: int) -> bool:
        if len(hand) % groupSize != 0 :
            return False
        count = Counter(hand)
        for i in sorted(count):
            if count[i] == 0:
                continue
            for j in range(1, groupSize):
                if count[i + j] < count[i]:
                    return False
                count[i + j] -= count[i]
        return True