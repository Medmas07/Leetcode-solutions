/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/*false
struct TreeNode* increasingBST(struct TreeNode* root) {
   if(root == NULL)
   return NULL;
   else if((root->left== NULL && root->right==NULL))
   return root;
   else
   {
       struct TreeNode*t=increasingBST(root->left);
       struct TreeNode*tmp=t;
       while(tmp!=NULL && tmp->right !=NULL)
       tmp=tmp->right;
       /*if(root->left!=NULL)
       tmp->right=root;
       root->left=NULL;
       struct TreeNode*u=root->right;
       root->right=increasingBST(u);


       return t;
   }
}*/

struct TreeNode* increasingBST(struct TreeNode* root) {

    if (root == NULL)
        return NULL;
    else if ((root->left == NULL && root->right == NULL))
        return root;
    else {
        struct TreeNode* t = increasingBST(root->left);
        struct TreeNode* tmp = t;
        while (tmp != NULL && tmp->right != NULL)
            tmp = tmp->right;

        if (tmp != NULL) // 6
            tmp->right = root;
        root->left = NULL;
        struct TreeNode* u = root->right;
        root->right = increasingBST(u);

        if (tmp == NULL)
            return root;
        return t;
    }
}