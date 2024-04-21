/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 struct ListNode* reverseList(struct ListNode* head) {
    if(head==NULL || head->next==NULL)
    return head;
    else
     {
        struct ListNode*tmp=reverseList(head->next);
        head->next->next=head;
        head->next=NULL;

        return tmp;
     }

    
}

unsigned int cdt(struct ListNode* head, int k)
{
    if(k==0 || k==1)
    return 1;
    int l=0;
    while(head!=NULL && l!=k)
    {
        head=head->next;
        l++;
    }
    return l<k;
}
/*
unsigned int cdt(struct ListNode* head, int k) {
    unsigned int count = 0;
    while (head != NULL && count < k) {
        head = head->next;
        count++;
    }
    return count;
}*/
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if(cdt(head,k))
    return head;
    else
    {
        int l=k;
        struct ListNode*tmp=head;
        while( l!=1)
        {
            tmp=tmp->next;
            l--;
        }
        struct ListNode*tmp1=tmp->next;
        tmp->next=NULL;
        tmp=reverseList(head);
        
        head->next=reverseKGroup(tmp1,k);
        return tmp;

    }
}