class Solution:
    def prisonAfterNDays(self, cells: list[int], n: int) -> list[int]:
        old = cells.copy()

        seen = {}
        day = {}
        for i in range(n):
            new = [0,0,0,0,0,0,0,0]
            for j in range(1,7):
                new[j] = int(old[j - 1] == old[j + 1])
            k = tuple(new)
            if (tuple(new) in seen):
                rem = (n - 1 - i) % (i - seen[k])
                print(i - seen[k])
                print(rem)
                return day[seen[k] + rem]
            else:
                seen[k] = i
                day[i] = new
            old = new 
        return old
