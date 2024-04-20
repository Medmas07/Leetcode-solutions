/*
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};
*/
// typedef struct ListNode* list;

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {

    struct ListNode* l = (struct ListNode*)malloc(sizeof(struct ListNode));
    l->next=NULL;
    struct ListNode* tmp = l;
    while (list1 != NULL && list2 != NULL) {
        //tmp = 
        //tmp->next = NULL;
       /* if (l == NULL) {
            l = tmp;
        }*/
        
        if (list1->val < list2->val) {
            tmp->next=list1;
            list1 = list1->next;
        } else {
            
            tmp->next=list2;
            list2 = list2->next;
        }
        tmp = tmp->next;
    }
    if (list1 == NULL)
        list1 = list2;
    tmp->next=list1;
    return l->next;
   
    
}
