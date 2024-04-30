/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode*reverse(struct ListNode*head)
{
    if(head ==NULL || head->next == NULL)
    {
        return head;
    }
    else
    {
        struct ListNode*t=reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return t;
    }
}


struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    
    if(left==right || head ==NULL)
    return head;
    else
    {struct ListNode* tmp=head;
    struct ListNode* tmp1=NULL;
     struct ListNode* tmp2=NULL;
    struct ListNode* before=NULL;
     struct ListNode* before1=NULL;
        while(right>1)
        {
            if(left==1)
            {before1=before;
                tmp1=tmp;
            }
            before=tmp;
            tmp=tmp->next;
            right--;
            left--;

        }
        if(before1==NULL)
        {
            tmp2=tmp->next;
        tmp->next=NULL;
        head=reverse(tmp1);
         tmp1->next=tmp2;
        }
else
       { tmp2=tmp->next;
        tmp->next=NULL;
        before1->next=reverse(tmp1);
        tmp1->next=tmp2;}
        return head;
    }
    
}