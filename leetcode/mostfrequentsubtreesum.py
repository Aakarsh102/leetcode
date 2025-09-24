# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.d = {}
        self.freq = {}
    def findFrequentTreeSum(self, root: Optional[TreeNode]) -> List[int]:
        if (root == None):
            return 
        self.recurse(root)
        # l = list(self.freq.values())
        m = -1000000
        ret = []
        for k,v in self.freq.items():
            if (v > m):
                m = v
                ret.clear()
            if v == m:
                ret.append(k)
        return ret

    def recurse(self, root):
        if (root == None):
            return 0
        if (self.d.get(root, -1) != -1):
            return self.d[root]
        left = self.recurse(root.left)
        right = self.recurse(root.right)
        k = left + right + root.val
        self.d[root] = k
        if (self.freq.get(k, -1) == -1):
            self.freq[k] = 1
        else:
            self.freq[k] += 1
        return k
