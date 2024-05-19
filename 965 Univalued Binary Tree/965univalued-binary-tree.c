/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isUnivalTree(struct TreeNode* root) {
    if(root==NULL || (!root->left && !root->right))
    return 1;
    else if(root->right!=NULL && root->val== root->right->val && root->left==NULL)
    return isUnivalTree(root->right);
    else if(root->left!=NULL && root->val== root->left->val && root->right==NULL)
    return isUnivalTree(root->left);
    else if(root->left!=NULL && root->right!=NULL && root->val== root->right->val && root->val == root->left->val)
    return isUnivalTree(root->right)&& isUnivalTree(root->left);
    else
    return 0;
}