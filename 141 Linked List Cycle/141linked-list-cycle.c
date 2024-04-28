/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
  /* int l=0;
   while(head !=NULL && l<(10*10*10*10))
   {l++;
    head =head->next;
   }
   return head!=NULL;*/
if(head==NULL || head->next ==NULL)
return 0;
   struct ListNode*tmp=head;struct ListNode*fast=head;
   do
   {
    tmp=tmp->next;
    fast=fast->next->next;
   }while(fast!=NULL && fast->next !=NULL && fast!=tmp);
return fast==tmp;
}