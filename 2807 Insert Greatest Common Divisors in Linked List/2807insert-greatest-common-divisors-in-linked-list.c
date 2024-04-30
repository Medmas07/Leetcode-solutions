/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* insert(struct ListNode* head, struct ListNode* tmp) {
    int a = head->val, b = tmp->val, temp=0;
     while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    struct ListNode* k = malloc(sizeof(struct ListNode));
    k->val = a;
    k->next = tmp;
    head->next = k;
    return k;
}

struct ListNode* insertGreatestCommonDivisors(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;
    else {
        struct ListNode* tmp = head;
        while (tmp != NULL && tmp->next != NULL) {
            tmp = insert(tmp, tmp->next);
            tmp=tmp->next;
        }
        return head;
    }
}