/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
    if(root==NULL)
    return 0;
    else {
        int ll=maxDepth(root->right),lr=maxDepth(root->left);
        if(ll<lr)
        return lr+1;
        else
        return ll+1;
    }
    
}