/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* tmp=head;struct ListNode *before=head;
    
    while(head!=NULL && head->val == val)
    {
        tmp=head;
        head=head->next;
        free(tmp);
        tmp=NULL;
    }
    if(head!=NULL)
    {
    before =head;
    tmp=head->next;
    while(tmp!=NULL)
    {
        if(tmp->val == val)
        {
            before->next =tmp->next;
            free(tmp);tmp=NULL;
            tmp=before->next;
        }
        else
        {
            before=tmp;
            tmp=tmp->next;
        }
    }}
    return head;
}