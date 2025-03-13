class Solution:
    def wordBreak(self, s: str, wordDict: list[str]) -> bool:
        dic = {i:1 for i in wordDict}

        dp = [0 for _ in range(len(s) + 1)]
        for i in range(1, len(s) + 1):
            if dic.get(s[:i], 0) == 1:
                dp[i] = 1
            else:
                for j in range(1, i):
                    if dp[i - j] == 1 and dic.get(s[i-j:i], 0) == 1:
                        dp[i] = 1
                        break
                    else:
                        continue
        return (dp[len(s)] == 1)
    
