# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
def affiche(nodes):
    l=[]
    for i in nodes:
        l.append(i.val)
    print(l)
def mirror(nodes):
    l=len(nodes)
    affiche(nodes)
    for i in range(l/2):
        nodes[i].val,nodes[l-1-i].val=nodes[l-1-i].val,nodes[i].val
    affiche(nodes)
    return nodes
        
        
class Solution(object):
    def reverseOddLevels(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: Optional[TreeNode]
        """
        def recurse(node1,node2,level):
            if not(node1 and node2):
                return
            else :
                if(level%2==0):
                    node1.val,node2.val=node2.val,node1.val
                recurse(node1.right,node2.left,level+1)
                recurse(node1.left,node2.right,level+1)
        recurse(root.left,root.right,0)
        return root
#         w=[]
#         q=[]
#         def preorder(root):
#             q.append(root)
#             while q:
#                 current=q.pop(0)
#                 w.append(current)
#                 if current.left:
#                     q.append(current.left)
#                     q.append(current.right)
#         preorder(root)
    
#         affiche(w)    
#         i=0
       
#         l=len(w)
#         j=2**0
#         tmp=[]
#         while(j<l):
#             if(i%2==0):
#                 tmp=w[j:j+2**(i+1)]
#                 mirror(tmp)
#             i+=1
#             j=j+2**(i)
#         return root
