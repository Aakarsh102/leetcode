from typing import List
class Solution:
    def minimumEffort(self, tasks: List[List[int]]) -> int:
        tasks.sort(key = lambda x : x[1] - x[0])
        print(tasks)
        ret = 0
        for i in tasks:
            ret = max(ret + i[0], i[1])

        return ret

        