/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

 /* time limit
struct ListNode* enfile(struct ListNode* l, int val) {
    struct ListNode* k = malloc(sizeof(struct ListNode));
    k->val = val;
    k->next = NULL;
    if (l == NULL)
        return k;
    else {
        struct ListNode* tmp = l;
        while (l != NULL && l->next != NULL)
            l = l->next;
        l->next = k;
        return tmp;
    }
}

struct ListNode* mergeNodes(struct ListNode* head) {
    struct ListNode* tmp = head->next;
    struct ListNode* t = NULL;
    int s = 0;
    while (tmp != NULL) {
        s += tmp->val;
        if (tmp->val == 0) {
            t = enfile(t, s);
            s = 0;
            // t = enfile(t, 0);
        }
        tmp=tmp->next;
    }return t;
}*/

struct ListNode* mergeNodes(struct ListNode* head) {
    struct ListNode* tmp = head->next;
    struct ListNode* t = NULL;
     struct ListNode* before = NULL;
    while (tmp != NULL && tmp->next !=NULL) {
        before=tmp;
        if(tmp->next->val !=0)
        {tmp->val += tmp->next->val;
        t=tmp->next;
        tmp->next=tmp->next->next;
        free(t);}
        else
        tmp=tmp->next;
        
    }
    if(before!=NULL)
    before->next =NULL ;
    return head->next;
}