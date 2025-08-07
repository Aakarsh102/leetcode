from collections import Counter
class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        if (len(word1) != len(word2)):
            return False
        w1_dict = dict(Counter(word1))
        w2_dict = dict(Counter(word2))
        for i in w1_dict:
            if w2_dict.get(i, 0) == 0:
                return False

        k = sorted(list(w1_dict.values()))
        l = sorted(list(w2_dict.values()))
        if k != l:
            return False

        return True
        


        