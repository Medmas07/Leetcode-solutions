/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/*
unsigned int valeur(struct ListNode* head) {
    if(head == NULL)
    return 0;
    else if (head->next == NULL)
        return head->val;
    else
        return (head->val)  + valeur(head->next)* 10;
}

struct ListNode* inverser(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;
    else {
        struct ListNode* tmp = inverser(head->next);
        head->next->next = head;
        head->next = NULL;
        return tmp;
    }
}

bool isPalindrome(struct ListNode* head) {
    if (head == NULL)
        return 0;
    else {
        unsigned int v = valeur(head);
        struct ListNode* tmp = inverser(head);
        if (v == valeur(tmp))
            return 1;
        else
            return 0;
    }
}*/
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *prev = NULL, *current = head, *next;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

// Function to find the middle of the linked list
struct ListNode* findMiddle(struct ListNode* head) {
    struct ListNode *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Function to check if a linked list is a palindrome
bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return true; // Empty list or single node is a palindrome

    struct ListNode *middle = findMiddle(head);
    struct ListNode *secondHalf = reverseList(middle);
    struct ListNode *firstHalf = head;

    // Compare the first half with the reversed second half
    while (secondHalf != NULL) {
        if (firstHalf->val != secondHalf->val)
            return false; // Not a palindrome
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return true; // Palindrome
}
