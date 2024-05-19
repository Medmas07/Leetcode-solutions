/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool autre(struct TreeNode* root, int ts, int current) {
    if (root == NULL)
        return 0;
    else if (!root->right && !root->left && (current+root->val) == ts)
        return 1;
    else
        return (autre(root->right, ts, current + root->val) ||
                autre(root->left, ts, current + root->val));
}

bool hasPathSum(struct TreeNode* root, int targetSum) {

    return autre(root,targetSum,0);
}