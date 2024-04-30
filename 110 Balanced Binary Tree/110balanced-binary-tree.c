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
         return (ll > lr ? ll : lr) + 1;
    }
    
}
bool isBalanced(struct TreeNode* root) {
    if(root==NULL )
    return 1;
    int leftHeight = maxDepth(root->left);
    int rightHeight = maxDepth(root->right);
    
    if(( leftHeight -rightHeight)<=1 && ((-leftHeight+rightHeight)<=1))
    return isBalanced(root->left) && isBalanced(root->right);
    else
    return 0;
  
}