class Solution:
    def findAnagrams(self, s: str, p: str) -> list[int]:
        if len(s) < len(p):
            return []
        ret = []
        window = len(p)
        d = {}
        for i in p:
            if d.get(i, -1) == -1:
                d[i] = 1
            else:
                d[i] += 1

        def check_zero():
            for k,v in d.items():
                if v!=0:
                    return False

            return True

        for i in s[0:window]:
            k = d.get(i, window + 1)
            if k != window + 1:
                d[i] -= 1
        if check_zero():
            ret.append(0)

        
                
        for i in range(1, len(s) - window + 1):
            if d.get(s[i - 1], window + 1) != window + 1:
                d[s[i - 1]] += 1
            if d.get(s[i + window - 1], window + 1) != window + 1:
                d[s[i + window - 1]] -= 1
            
            if check_zero():
                ret.append(i)

        return ret

            

                
                