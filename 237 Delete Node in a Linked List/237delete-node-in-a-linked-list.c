/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    struct ListNode*tmp=NULL;
    while(node!=NULL && node->next !=NULL)
    {
        node->val=node->next->val;
        tmp=node;
        node=node->next;
    }
    if(tmp!=NULL)
    {
        tmp->next=NULL;
       // free(node);
    }
}