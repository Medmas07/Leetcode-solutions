/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

 bool verif(struct TreeNode*root,struct TreeNode*subRoot)
 {
    if(root==NULL && subRoot==NULL)
    return 1;
    else if(root==NULL || subRoot==NULL)
    return 0;
    else if(root->val == subRoot->val)
    return verif(root->right,subRoot->right)&&verif(root->left,subRoot->left);
    else
    return 0;
 }
bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
    if(root==NULL)
    return 0;
    else if(root->val==subRoot->val)
    return verif(root,subRoot)||isSubtree(root->right,subRoot)||isSubtree(root->left,subRoot);
    else
    return isSubtree(root->right,subRoot)||isSubtree(root->left,subRoot);
}