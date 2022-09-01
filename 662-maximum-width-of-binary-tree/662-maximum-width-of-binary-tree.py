# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def widthOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        dic={}
        def rt(root,l,w):
            if not root:
                return
            if not l in dic:
                dic[l]=[w]
            else:
                dic[l].append(w)
            rt(root.left,l+1,2*w+1)
            rt(root.right,l+1,2*w+2)
        rt(root,0,0)
        keys=sorted(dic,reverse=True)
        ma=-10000000000000
        for i in range(len(keys)):
            ma=max(ma,(max(dic[keys[i]])-min(dic[keys[i]])))
        return ma+1
            
        