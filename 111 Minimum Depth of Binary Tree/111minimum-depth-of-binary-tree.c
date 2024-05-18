/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int minDepth(struct TreeNode* root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL)
        return 1+minDepth(root->right);
    else {
        int l = minDepth(root->left);
        int r = minDepth(root->right);
        if (r < l) {
            if (r == 0)
                return l + 1;
            else
                return r + 1;
        } else {
            if (l == 0)
                return r + 1;
            else
                return l + 1;
        }
    }
}