class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        dp = [[-1 for i in range(len(nums) + 1)] for j in range(len(nums) + 1)]
        nums = [1] + nums + [1]
        
        def recurse(left, right):
            if (left > right):
                return 0
            if dp[left][right] != -1:
                return dp[left][right]
            for i in range(left, right + 1):
                total = nums[i] * nums[left - 1] * nums[right + 1] + recurse(i + 1, right) + recurse(left, i - 1)
                dp[left][right] = max(dp[left][right], total)

            return dp[left][right]
        return recurse(1, len(nums) - 2)


            
        