/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int abs(int a)
{
    if(a<0)
    return -a;
    else
    return a;
}

int sum(struct TreeNode*root)
{
    if(root==NULL)
    return 0;
    else
    return root->val+sum(root->right)+sum(root->left);
}

int findTilt(struct TreeNode* root) {
    if(root==NULL)
    return 0;
    else if(root->right==NULL && !root->left)
    return 0;
    else if(root->right ==NULL)
    return abs(sum(root->left))+findTilt(root->left);
    else if(root->left == NULL)
    return abs(sum(root->right))+findTilt(root->right);
    else 
    return abs(sum(root->right)-sum(root->left))+findTilt(root->left)+findTilt(root->right);

}