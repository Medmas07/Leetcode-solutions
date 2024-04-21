/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int getDecimalValue(struct ListNode* head) {
    int s=0;
    while(head!=NULL)
    {
        s=2*s+head->val;
        head=head->next;
    }
    return s;
}