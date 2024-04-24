/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* min(struct ListNode** lists, int n) {
    if (n != 0) {
        int m = 0, o = 0;
        while (lists[o] == NULL) {
            o++;
        }
        m = lists[o]->val;
        struct ListNode* t = lists[o];
        for (int i = 0; i < n; i++) {
            if (lists[i] == NULL)
                continue;
            else if (m > lists[i]->val) {
                m = lists[i]->val;
                t = lists[i];
                o = i;
            }
        }
        if (lists[o] != NULL)
            lists[o] = lists[o]->next;
        return t;
    } else
        return NULL;
}

unsigned int vide(struct ListNode** lists, int n) {
    int i = 0;
    while (i < n && lists[i] == NULL)
        i++;
    return i == n;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    struct ListNode* l = NULL;
    struct ListNode* tmp = NULL;
    while (!(vide(lists, listsSize))) {
        struct ListNode* minn = min(lists, listsSize);
        if (minn == NULL)
            break;
        else if (l == NULL) {
            l = minn;
            tmp = l;
        } else if (tmp != NULL) {
            tmp->next = minn;
            tmp = tmp->next;
        }
    }

    return l;
}