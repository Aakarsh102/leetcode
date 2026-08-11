# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.max_val = -300000001
    def maxPathSum(self, root) -> int:
        if (root.left is None and root.right is None):
            return root.val
        self.do_bottom_up(root)
        return self.max_val

    def do_bottom_up(self, root):
        if (root is None):
            return -1
        l = self.do_bottom_up(root.left)
        r = self.do_bottom_up(root.right)
        self.max_val = max(self.max_val, l + root.val, r + root.val, l+r+root.val, root.val)
        return root.val + max(l, r, 0)


        