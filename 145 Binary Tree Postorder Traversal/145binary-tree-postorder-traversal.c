/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    int* t = NULL;
    if (root == NULL) {
        *returnSize = 0;
        return t;
    } else {
        int rd = 0, rg = 0;
        int* td = postorderTraversal(root->right, &rd);
        int* tg = postorderTraversal(root->left, &rg);
        t = (int*)malloc(sizeof(int) * (rd + rg + 1));
        for (int i = 0; i < rd + rg + 1; i++) {
            if (i < rg)
                t[i] = tg[i];
            else if (i < rd+rg && rg <= i)
                t[i] = td[i - rg];
            else
                t[i] = root->val;
        }
        *returnSize = rd + rg + 1;
        return t;
    }
}