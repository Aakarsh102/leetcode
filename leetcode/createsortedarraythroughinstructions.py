class Solution:
    def createSortedArray(self, instructions: list[int]) -> int:
        n = max(instructions)
        nums = [0] * (n + 1)

        def adder(val):

            k = val
            while k <= n:
                nums[k] += 1
                k += k & -k 
        def presum(val):
            total = 0
            ind = val
            while ind > 0: 
                total += nums[ind]
                ind -= ind & -ind
            return total 
        ret = 0
        for i in range(len(instructions)):
            instruction = instructions[i]
            less = presum(instruction - 1)
            greater = i - presum(instruction)
            adder(instruction)  
            ret = (ret + min(less, greater) ) 

        return ret % 1000000007
