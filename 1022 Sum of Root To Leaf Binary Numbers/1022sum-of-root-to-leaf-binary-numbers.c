/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int dfs(struct TreeNode*root,int current)
{
if(!root)
return 0;
    current=(current<<1)|root->val;
    if(root->left ==NULL && root->right ==NULL)
    return current;
    else
    return dfs(root->right,current)+dfs(root->left,current);
}

int sumRootToLeaf(struct TreeNode* root) {
    
    return dfs(root,0);
}