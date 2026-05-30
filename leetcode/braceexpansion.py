class Solution:
    def expand(self, s: str) -> List[str]:
        cur = []
        res = []
        self.do_back(res, s, 0, cur)
        return res
        
    def extract(self, s, i):
        j = s.find('}', i+1)
        l = s[i + 1: j].split(',')
        l.sort()
        return l, j + 1
    
    def do_back(self, res, s, i, cur):
        if i == len(s):
            return res.append(''.join(cur))
        if s[i] != '{':
            cur.append(s[i])
            self.do_back(res, s, i + 1, cur)
            cur.pop()
        else: 
            l, j = self.extract(s, i)
            for k in l:
                cur.append(k)
                print(cur)
                self.do_back(res, s, j, cur)
                cur.pop()

            