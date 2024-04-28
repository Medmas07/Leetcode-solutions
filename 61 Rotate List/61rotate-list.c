/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 *//*
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (k == 0 || head == NULL)
        return head;
   
    struct ListNode* tmp = head;
    struct ListNode* tmp1 = NULL;
    int l = 0;
    int k1 = k;
    while (tmp != NULL) {
        tmp = tmp->next;
        l++;
    }
    k1 = k1 % l;
    if (k1 == 0)
        return head;
    tmp = head;
    k = l-k1;
    while (tmp != NULL && tmp->next != NULL) {

        
        tmp = tmp->next;
        k--;
        if (k == 0)
            tmp1 = tmp;
    }/*
if(tmp==tmp1)
{
    tmp1=
}
    tmp->next = head;
    struct ListNode* tmp2 = tmp1->next;
    tmp1->next = NULL;
    return tmp2;
}*/

struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (k == 0 || head == NULL)
        return head;
   
    struct ListNode* tmp = head;
    struct ListNode* tmp1 = NULL;
    int l = 0;
    int k1 = k;
    while (tmp != NULL) {
        tmp = tmp->next;
        l++;
    }
    k1 = k1 % l;
    if (k1 == 0|| head == NULL)
        return head;
    tmp = head;
    printf("k1 ;%d\n",k1);
    printf("l ;%d\n",l);
    k = l-k1;
    printf("k ;%d\n",k);
    while (tmp != NULL && tmp->next != NULL) {
        if (k == 1)
            tmp1 = tmp;
        tmp = tmp->next;
        k--;
        if (k == 1)
            tmp1 = tmp;
    }
    /*
if(tmp==tmp1)
{
    tmp1=
}*/printf("tmp1 val ;%d\n",tmp1->val);
if(tmp1==tmp)
{
    tmp->next = head;
   
    tmp->next->next = NULL;
    return tmp1;
}
    tmp->next = head;
    struct ListNode* tmp2 = tmp1->next;
    tmp1->next = NULL;
    return tmp2;
}