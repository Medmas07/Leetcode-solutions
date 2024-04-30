/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */

int pos(struct Node* head, struct Node* t) {
    int i = 0;
    while (head != NULL && head != t) {
        i++;
        head = head->next;
    }
    return i;
}

struct Node* point(struct Node* head, int p) {
    while (head != NULL && p != 0) {
        head = head->next;
        p--;
    }
    return head;
}

struct Node* copyRandomList(struct Node* head) {
    struct Node* cpy = NULL;
    struct Node* cpyh = NULL;
    struct Node* tmp = head;
    struct Node* before = NULL;
    while (tmp != NULL) {
        cpy = (struct Node*)malloc(sizeof(struct Node));
        cpy->val = tmp->val;
        cpy->next = NULL;
        if (before != NULL)
            before->next = cpy;
        else
            cpyh = cpy;
        before = cpy;
        //cpy = cpy->next;
        tmp = tmp->next;
    }
    tmp = head;
    cpy = cpyh;
    while (tmp != NULL) {
        cpy->random = point(cpyh, pos(head, tmp->random));
        cpy = cpy->next;
        tmp = tmp->next;
    }
    return cpyh;
}