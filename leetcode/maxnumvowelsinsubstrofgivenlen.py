class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        start = 0
        vowels = {'a' : 0, 'e' : 0, 'i' : 0, 'o' : 0, 'u' : 0}
        count = 0
        max_count = 0
        for i in range(k):
            if vowels.get(s[i], -1) != -1:
                vowels[s[i]] += 1
        for (key, value) in vowels.items():
            count += value
        max_count = max(count, max_count)
        for start in range(1, len(s) - k + 1):
            if vowels.get(s[start - 1], 0) != 0:
                vowels[s[start - 1]] -= 1
                count -= 1
            if vowels.get(s[start + k - 1], -1) != -1:
                vowels[s[start + k - 1]] += 1
                count += 1
            max_count = max(count, max_count)
            if max_count == k:
                return k

        return max_count