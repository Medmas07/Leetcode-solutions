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
char** binaryTreePaths(struct TreeNode* root, int* returnSize) {

    if (root->right == NULL && root->left == NULL) {
        char** t = malloc(sizeof(char*));
        *returnSize = 1;
        char ch[5];
        sprintf(ch, "%d", root->val);
        t[0]=malloc(5);
        strcpy(t[0],ch);
        return t;
    } else {
        int rd = 0, rg = 0;char** td=NULL; char** tg =NULL;
        if (root->right != NULL)
            td = binaryTreePaths(root->right, &rd);
        if (root->left != NULL)
             tg = binaryTreePaths(root->left, &rg);
        char** t = malloc(sizeof(char*) * (rd + rg));
        char ch[10];
        sprintf(ch, "%d->", root->val);
        for (int i = 0; i < rd; i++) {
             t[i] = malloc(strlen(ch) + strlen(td[i]) + 1); // Allocate memory for the concatenated string
            strcpy(t[i], ch);
            strcat(t[i], td[i]);
        }
        for (int i = rd; i < rd + rg; i++) {
             t[i] = malloc(strlen(ch) + strlen(tg[i - rd]) + 1); // Allocate memory for the concatenated string
            strcpy(t[i], ch);
            strcat(t[i], tg[i - rd]);
        }
        *returnSize=rd+rg;
        return t;
    }
}