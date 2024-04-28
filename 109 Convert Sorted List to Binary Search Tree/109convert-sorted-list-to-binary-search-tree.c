/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 *//*
int longueur(struct ListNode* haed) {
    int l = 0;
    while (haed != NULL) {
        l++;
        haed = haed->next;
    }
    return l;
}

int middle(struct ListNode* headL, struct ListNode** headR) {
    int l = longueur(headL), i = 0;
    struct ListNode* tmp = headL;
    struct ListNode* before = NULL;
    while (i < (l / 2)) {
        before = tmp;
        tmp = tmp->next;
        i++;
    }
    //if (tmp != NULL)
        int a = tmp->val;
        before->next = NULL;
        *headR = tmp->next;
        free(tmp);
        return a;
    
}

struct TreeNode* sortedListToBST(struct ListNode* head) {
    if (head == NULL)
        return NULL;
    else {
        struct TreeNode* t = malloc(sizeof(struct TreeNode));
        struct ListNode* headR = NULL;
        int a = middle(head, &headR);
        t->val = a;
        t->left = sortedListToBST(head);
        t->right = sortedListToBST(headR);
        return t;
    }
}*/
int longueur(struct ListNode* haed) {
    int l = 0;
    while (haed != NULL) {
        l++;
        haed = haed->next;
    }
    return l;
}

int middle(struct ListNode** headL, struct ListNode** headR) {
    int l = longueur(*headL), i = 0;
    struct ListNode* tmp = *headL;
    struct ListNode* before = NULL;
    if(l<=1)
    {
        i=(*headL)->val;
        free(*headL);
        *headL=NULL;
        return i;
    }
    while (i < (l / 2)) {
       // printf("d5al\n");
        //printf("before %u\n",before);
        before = tmp;
        tmp = tmp->next;
        i++;
    }
    //if (tmp != NULL)
        int a = tmp->val;
        if(before!=NULL)
        before->next = NULL;
        *headR = tmp->next;
        free(tmp);
        return a;
    
}

struct TreeNode* sortedListToBST(struct ListNode* head) {
    if (head == NULL)
        return NULL;
    else {
        struct TreeNode* t = malloc(sizeof(struct TreeNode));
        struct ListNode* headR = NULL;
        int a = middle(&head, &headR);
        t->val = a;
        t->left = sortedListToBST(head);
        t->right = sortedListToBST(headR);
        return t;
    }
}