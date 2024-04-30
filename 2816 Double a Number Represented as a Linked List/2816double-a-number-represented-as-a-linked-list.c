/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

 typedef struct ListNode*stack;
stack empile(stack head ,int a)
{
    stack t=malloc(sizeof(struct ListNode));
    t->val=a;
    t->next=head;
    return t;
}
stack depile(stack p)
{
    if(p!=NULL)
    {
        stack tmp=p;
        p=p->next;
        free(tmp);tmp=NULL;
        return p;
    }
    else
    return NULL;
}
struct ListNode* doubleIt(struct ListNode* head){
stack p=NULL;
while(head!=NULL)
{
    if(head->val >4 && p==NULL)
    {p=empile(p,1);
    p=empile(p,((head->val)*2)-10);}
    else if(head->val>4)
    {
        p->val+=1;
        p=empile(p,((head->val)*2)-10);
    }
    else
    p=empile(p,(head->val)*2);
head=depile(head);
}
while(p!=NULL)
{
head=empile(head,p->val);
p=depile(p);
}return head;
}