/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    if(head == NULL || head->next==NULL)
    return head;
    else
    {struct ListNode*tmp=head->next->next;
    struct ListNode*tmp1=head->next;
        head->next->next=head;
        head->next=swapPairs(tmp);
        return tmp1;
    }




}