class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2):
            return False
        k = {}
        for i in s1:
            if (k.get(i, 0) == 0):
                k[i] = 1
            else:
                k[i] += 1
        start = 0
        end = len(s1) - 1
        for i in s2[start:end+1]:
            if k.get(i, 0) == 0:
                k[i] = -1
            else:
                k[i] -= 1
        while end < len(s2):
            done = True
            for value in k.values():
                if value != 0:
                    done = False

            if done == True:
                return True
            end += 1
            k[s2[start]] += 1
            if (end < len(s2)):
                if k.get(s2[end], 0) == 0:
                    k[s2[end]] = -1
                else:
                    k[s2[end]] -= 1
            
            start += 1
        return False 




        
        