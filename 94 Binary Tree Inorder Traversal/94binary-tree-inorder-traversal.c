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
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    if(root == NULL)
    {
        *returnSize = 0;
        return NULL;
    }
    else
    {
       /* int *t=malloc(sizeof(int));
        *returnSize++;
        t[0]=root->val;*/
        int *ur=NULL;int *ul=NULL;
        int rr=0;
        int rl=0;
        ur=inorderTraversal(root->right,&rr);
        ul=inorderTraversal(root->left,&rl);
        *returnSize=rl+rr+1;
        int *t=malloc(sizeof(int)*(*returnSize));
         
        for(int i=0;i<rl;i++)
        {
           t[i]=ul[i];
        }
        t[rl]=root->val;
        for(int i=0;i<rr;i++)
        {
           t[i+rl+1]=ur[i];
        }
        free(ul);
    free(ur);

        return t;
    }
}