class Solution:
    def mergeTriplets(self, triplets: list[list[int]], target: list[int]) -> bool:
        first = False
        second = False
        third = False
        for i in triplets:
            if i[0] > target[0] or i[1] > target[1] or i[2] > target[2]:
                continue
            else: 
                if i[0] == target[0]:
                    first = True
                if i[1] == target[1]:
                    second = True
                if i[2] == target[2]:
                    third = True
                if first and second and third:
                    return True
        return False