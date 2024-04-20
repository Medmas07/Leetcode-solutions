
 /* //Definition for singly-linked list.
struct ListNode {
      int val;
      struct ListNode *next;
  };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    int d=0;
    struct ListNode*tmp=head;
    while(head!=NULL && head->next!=NULL)
    {d=head->next->val;
        if(head->val == d)
        {
            struct ListNode*tmp1=head->next;
            head->next=head->next->next;
            free(tmp1);

            

        }
        else
        head=head->next;
    }
    return tmp;
}