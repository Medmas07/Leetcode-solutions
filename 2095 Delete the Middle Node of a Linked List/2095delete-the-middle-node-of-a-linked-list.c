/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteMiddle(struct ListNode* head) {
    struct ListNode* tmp=head;
    int n=0;
    while(tmp!=NULL){
        tmp=tmp->next;
        n++;
    }
    if(n/2==0){
        head=head->next;
        return head;
    }
    tmp=head;
    struct ListNode* prev=head;
    int i=0;
    while(i<n/2){
        i++;
        prev=tmp;
        tmp=tmp->next;
    }
    prev->next=tmp->next;
    return head;

}