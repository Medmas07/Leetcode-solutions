/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode* list;
int pairSum(struct ListNode* head) {
    int n=0;
    list tmp=head;
    while(tmp!=NULL)
    {
        tmp=tmp->next;
        n++;
    }
    int*t=malloc(sizeof(int)*n);
    tmp=head;
    for(int i=0;i<n;i++)
    {
        t[i]=tmp->val;
        tmp=tmp->next;
    }
    int max=0;
    for(int i=0;i<n/2;i++)
    {
        if((t[i]+t[n-1-i])>max)
            max=t[i]+t[n-1-i];
    }
    free(t);
    return max;
}