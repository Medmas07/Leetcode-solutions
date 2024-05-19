/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/*
int max(struct TreeNode*root,int m)
{
   if(root->val >m)
   return max()
}*/

int findSecondMinimumValue(struct TreeNode* root) {
    int min = 2147483647;
    int min2 = 2147483647;
    int b=0;

    void trav(struct TreeNode * root) {
        if (root == NULL)
            return;
        else if (root->val < min) {
            min2 = min;
            min = root->val;
        } else if (root->val <= min2 && min<root->val)
            {min2 = root->val;b=1;}
        trav(root->right);
        trav(root->left);
    }
    trav(root);
    if (min2 == min || b==0)
        return -1;
    else
        return min2;
}