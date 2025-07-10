class Solution:
    def checkValidString(self, s: str) -> bool:
        mi = 0
        ma = 0

        for i in s:
            if i == '(':
                ma += 1
                mi += 1
            elif i == ')':
                ma -= 1
                mi -= 1
            else:
                ma += 1
                mi -= 1

            if (mi < 0):
                mi = 0
                
            if (ma < 0):
                return False  
        return mi == 0 
            

            

        