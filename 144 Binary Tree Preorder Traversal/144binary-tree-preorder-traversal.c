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
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int* t = NULL;
    * returnSize = 0;
    if (root == NULL)
        return t;
    else {
        int rd = 0, rg = 0;
        int* td = preorderTraversal(root->right, &rd);
        int* tg = preorderTraversal(root->left, &rg);
        t = (int*)malloc(sizeof(int) * (rg + rd + 1));
        for (int i = 0; i < rd + rg + 1; i++) {
            if (i == 0)
                t[i] = root->val;
            else if (i < rg + 1)
                t[i] = tg[i - 1];
            else
                t[i] = td[i - 1 - rg];
        }
        *returnSize = rg + rd + 1;
        return t;
    }
}