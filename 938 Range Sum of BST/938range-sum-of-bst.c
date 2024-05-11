/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 /*
int rangeSumBST(struct TreeNode* root, int low, int high) {
    if(root==NULL)
    return 0;
    else 
    {
        int r=0,l=0;
        if(root->val <=high  && low<= root->val)
        {
            r=rangeSumBST(root->right,low,high);
        l=rangeSumBST(root->left,low,high);
        return l+r+root->val;}
        else if(root->val<low)
        return rangeSumBST(root->right,low,high);
        else if(high<root->val)
        return rangeSumBST(root->left,low,high);
        else return 0;

        
    }
}*/
int rangeSumBST(struct TreeNode* root, int low, int high) {
    if (root == NULL) return 0; 
    if (root->val < low) return rangeSumBST(root->right, low, high);
    if (root->val > high) return rangeSumBST (root->left, low, high);
    
    
    return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    
}