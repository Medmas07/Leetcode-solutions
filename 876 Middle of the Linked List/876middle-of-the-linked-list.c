/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head) {
    int l=1;
    struct ListNode*tmp=head;
    while(tmp!=NULL)
    {
        l++;
        tmp=tmp->next;
    }
    
    int k=l/2;
    while(l!=1 && k!=1)
    { 
        head=head->next;
       k--;

    }
    if(l%2==0)
    return head;
    else
    return head->next;
   

}