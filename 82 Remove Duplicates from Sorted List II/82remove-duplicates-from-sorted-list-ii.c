/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* delete(struct ListNode* head) {
    if (head != NULL) {
        struct ListNode* tmp = head->next;
        free(head);
        return tmp;

    } else
        return NULL;
}

struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* tmp = head;
    struct ListNode* tmp1 = NULL;
    struct ListNode* before = NULL;
    int a = 0;
    while (tmp != NULL ) {

        if (tmp->next != NULL && tmp->val == tmp->next->val) {
            tmp->next = delete (tmp->next);
            a = 1;
        } else if (a == 1) {
            if (before != NULL) {
                before->next = delete (tmp);
                
                tmp = before->next;
            }
            else{
                head=delete(head);
                tmp=head;
            }a = 0;
        } else {
            before = tmp;
            tmp = tmp->next;
        }
    }
    return head;
}