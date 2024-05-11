/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* mergeTrees(struct TreeNode* root1, struct TreeNode* root2) {
    if(!(root1 - root2))
    return NULL;
    else if(root1==NULL )
    return root2;
    else if(root2==NULL)
    return root1;
    else
    {
        struct TreeNode*root=malloc(sizeof(struct TreeNode));
        root->val=root1->val +root2->val;
        root->right=mergeTrees(root1->right,root2->right);
        root->left=mergeTrees(root1->left,root2->left);
return root;
    }
}