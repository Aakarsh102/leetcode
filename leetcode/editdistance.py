class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        if (len(word1) == 0 or len(word2) == 0):
            return max(len(word1), len(word2))
        dp = [[0] * (len(word1) + 1) for _ in range(len(word2) + 1)]

        flag = False
        for i in range(1, len(word1)+1):
            if ( (not flag) and word1[i-1] == word2[0]):
                if (i != 0):
                    dp[1][i] = dp[1][i-1]
                flag = True
            else:
                dp[1][i] = dp[1][i-1] + 1
        flag=False
        for j in range(1, len(word2)+1):
            if ( (not flag) and word2[j-1] == word1[0]):
                if (j != 0):
                    dp[j][1] = dp[j-1][1]
                flag = True
            else:
                dp[j][1] = dp[j-1][1] + 1
        
        for i in range(2, len(word1)+1):
            for j in range(2, len(word2)+1):
                if word1[i-1] == word2[j-1]:
                    dp[j][i] = dp[j-1][i-1]
                else:
                    dp[j][i] = min((1+dp[j-1][i-1]), (1+dp[j][i-1]), (1+dp[j-1][i]))

        return dp[len(word2)][len(word1)]
                    