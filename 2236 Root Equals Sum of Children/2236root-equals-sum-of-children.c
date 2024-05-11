/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool checkTree(struct TreeNode* root) {
    if(root!=NULL && root->left !=NULL && root->right !=NULL)
    return (root->val ==(root->left->val + root->right->val));
    else
    return 0;
}