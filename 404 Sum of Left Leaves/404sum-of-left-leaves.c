/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int sumOfLeftLeaves(struct TreeNode* root) {
    if(root==NULL)
    return 0;
    if(!root->left && !root->right)
    return 0;
    else if(root->left!=NULL && root->left->left == NULL && root->left->right==NULL)
    return sumOfLeftLeaves(root->right)+root->left->val;
    else
    {
        return sumOfLeftLeaves(root->right)+sumOfLeftLeaves(root->left);
    }
}