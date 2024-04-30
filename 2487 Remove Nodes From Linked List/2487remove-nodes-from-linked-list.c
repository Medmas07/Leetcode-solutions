/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode* stack;
stack empile(stack p, int a) {
    stack k = malloc(sizeof(struct ListNode));

    k->next = p;
    k->val = a;
    return k;
}
stack depile(stack p) {
    if (p != NULL) {
        stack tmp = p;
        p = p->next;
        free(tmp);
        return p;
    } else
        return NULL;
}
struct ListNode* removeNodes(struct ListNode* head) {
    stack p = NULL;
    int m = 0;
    while (head != NULL) {
        if (m == 0) {
            p = empile(p, head->val);
            m = head->val;
        } else if (head->val > p->val) {
            while (p != NULL && p->val < head->val)
                p = depile(p);
            p = empile(p, head->val);
        } else {
            p = empile(p, head->val);
        }
        head = depile(head);
    }
    while(p!=NULL)
    {
        head=empile(head,p->val);
        p=depile(p);

    }
    return head;
}