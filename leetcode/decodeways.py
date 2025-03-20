class Solution:
    def numDecodings(self, s: str) -> int:
        if not s or s[0] == '0':
            return 0  # No valid decoding for strings starting with '0'

        n = len(s)
        dp = [0] * (n + 1)  # dp[i] means ways to decode s[:i]
        dp[0], dp[1] = 1, 1  # Base cases

        for i in range(2, n + 1):
            # Single digit decoding (1-9)
            if s[i - 1] != '0':
                dp[i] += dp[i - 1]

            # Two digit decoding (10-26)
            two_digit = int(s[i - 2:i])  # Convert substring s[i-2:i] to int
            if 10 <= two_digit <= 26:
                dp[i] += dp[i - 2]

        return dp[n]