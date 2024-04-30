/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool mirror(struct TreeNode*rootl, struct TreeNode*rootr)
{
    if(rootl==NULL && rootr==NULL)
    return 1;
    if(rootl==NULL || rootr==NULL)
    return 0;
    return ((rootl->val == rootr->val)&&(mirror(rootl->right,rootr->left)&&(mirror(rootr->right,rootl->left))));
}

bool isSymmetric(struct TreeNode* root) {
return mirror(root->left,root->right);
}