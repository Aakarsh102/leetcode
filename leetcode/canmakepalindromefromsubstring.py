class Solution:
    def canMakePaliQueries(self, s: str, queries: list[list[int]]) -> list[bool]:
        ans = []
        pre = [0]
        mask = 0
        for i in range(len(s)):
            mask ^= 1 << (ord(s[i]) - ord('a'))
            pre.append(mask)
        for i in range(len(queries)):
            query = queries[i]
            #sub = s[query[0]: query[1] + 1]
            k = query[2]
            # d = defaultdict(int) 
            # count = 0
            # for j in range(query[0], query[1] + 1):
            #     i = s[j]
            #     d[i] += 1
            #     if d[i] & 1 == 1:
            #         count += 1
            #     else:
            #         count -=1
            count = 0
            count = (pre[query[0]] ^ pre[query[1] + 1]).bit_count()
            # if flag:
            #     return ans
            # print(count)
            # print(pre)
            flag = True
            if count >> 1 > k:
                ans.append(False)
            else:
                ans.append(True)
            

        return ans
        
        