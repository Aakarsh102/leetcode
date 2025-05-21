class Solution:
    def partitionLabels(self, s: str) -> list[int]:
        last_occ = 0
        start = 0
        ret = []
        lastoccurences = {}
        for i in range(len(s) - 1, -1, -1):
            if (lastoccurences.get(s[i], -1) != -1):
                continue
            lastoccurences[s[i]] = i
        i = 0
        while (i < len(s)):
            last_occ = max(lastoccurences[s[i]], last_occ)
            if (i == last_occ):
                ret.append(i - start + 1)
                start = i + 1
            i += 1
            
        return ret