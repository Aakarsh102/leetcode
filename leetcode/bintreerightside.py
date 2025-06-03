# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque
class Solution:
    def rightSideView(self, root) -> list[int]:
        if not root:
            return []
        my = deque()
        res = []
        my.appendleft(root)
        while len(my) != 0:
            size = len(my)
            l = root.val
            for i in range(size):
                k = my.popleft()
                l = k.val
                
                if k.left:
                    my.append(k.left)
                if k.right:
                    my.append(k.right)
                

            res.append(l)

        return res