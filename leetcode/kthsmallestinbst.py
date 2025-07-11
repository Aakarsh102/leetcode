# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthSmallest(self, root, k: int) -> int:
        l = []
        stack = []

        node = root
        while True:
            while node:
                stack.append(node)
                node = node.left
            node = stack.pop()
            k -=1
            if (k == 0):
                return node.val
            node = node.right
                
        # def do(node):
        #     if (node == None):
        #         return
        #     do(node.left)
        #     l.append(node.val)
        #     do(node.right)
        # do(root)
        # return l[k-1]
