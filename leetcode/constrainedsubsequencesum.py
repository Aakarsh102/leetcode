from collections import deque
from typing import List

class Solution:
    def constrainedSubsetSum(self, nums: List[int], k: int) -> int:
        dp = [nums[0]]
        dq = deque()
        dq.append(0)
        i = 1
        m = dp[0]
        while i < len(nums):
            dp.append(max(dp[dq[0]] + nums[i], nums[i]))
            m = m if m > dp[-1] else dp[-1]
            while dq and dp[dq[-1]] < dp[i]:
                dq.pop()
            dq.append(i)
            if dq[0] < i - k + 1:
                dq.popleft()
            i += 1
        return m

