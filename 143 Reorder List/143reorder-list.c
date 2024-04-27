/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode*dernier(struct ListNode* head)
{
    if(head==NULL)
    return NULL;
    else
    {
        struct ListNode* y=head;struct ListNode*tmp=NULL;
        while(y->next !=NULL)
        {tmp=y;
            y=y->next;
        }
        if(tmp==NULL)
        return y;
        y->next=head;
        tmp->next=NULL;
        reorderList(head);
        return y;

    }
}

void reorderList(struct ListNode* head) {
    if(head !=NULL)
    head->next=dernier(head->next);
    
}