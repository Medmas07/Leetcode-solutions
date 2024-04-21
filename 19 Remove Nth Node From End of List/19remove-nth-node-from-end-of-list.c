/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

 int longueur(struct ListNode*l)
 {
    if(l==NULL)
    return 0;
    else
    return 1+longueur(l->next);
 }
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode*tmp=head;
    struct ListNode*before=head;
    int l=longueur(head)-n;
    while(l>1)
    {
        l--;

        tmp=tmp->next;

    }
    if(l==0)
    {return head->next;}
    else 
    {before=tmp->next;
    tmp->next=tmp->next->next;
    free(before);}
    return head;

}