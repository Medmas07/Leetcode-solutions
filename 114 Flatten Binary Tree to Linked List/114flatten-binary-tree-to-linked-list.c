/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void flatten(struct TreeNode* root) {
    if(root!=NULL)
    {
        struct TreeNode*t=root;
        struct TreeNode*t1=root->right;
        
        flatten(t->left);
        t->right=t->left;
        t->left=NULL;
        while(t!=NULL && t->right !=NULL)
        t=t->right;
        flatten(t1);
        t->right=t1;
        

    }
}