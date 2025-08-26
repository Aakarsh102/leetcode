
import math
from bisect import bisect_left
class Solution:
    def successfulPairs(self, spells: list[int], potions: list[int], success: int) -> list[int]:
        potions.sort()

        pairs = [0 for i in range(len(spells))]
        n = len(potions)
        for i in range(len(spells)):
            mul = math.ceil(success / spells[i])
            k = bisect_left(potions, mul)
            print(k)
            pairs[i] = n - k

        return pairs
