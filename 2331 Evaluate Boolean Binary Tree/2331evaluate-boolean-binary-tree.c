/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool evaluateTree(struct TreeNode* root) {
    if(root->right == NULL && root->left==NULL)
    return root->val;
    else
    {
        if(root->val == 2)
        return (evaluateTree(root->right)||evaluateTree(root->left));
        else return (evaluateTree(root->right)&& evaluateTree(root->left));
    }
}