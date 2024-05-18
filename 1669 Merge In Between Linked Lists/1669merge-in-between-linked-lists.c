/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2){
struct ListNode*before=NULL;
struct ListNode*tmp=list1;
int l=0;int v=0;
while(tmp!=NULL && l!=b)
{
    before=tmp;
    l++;
    tmp=tmp->next;
    if(a==l)
    {
        before->next=list2;v=1;
    }
    if(v==1 && list2 !=NULL && list2->next !=NULL)
    list2=list2->next;
}
while(list2 !=NULL && list2->next !=NULL)
list2=list2->next;
if(list2!=NULL)
list2->next=tmp->next;
return list1;
}