/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
   /* if (!headA || !headB)
        return NULL;*/
    struct ListNode*tmp1=headA;struct ListNode*tmp2=headB;
    while( tmp2 !=NULL && tmp1!= tmp2)
    {
        if(tmp1!=NULL)
        {
            tmp1=tmp1->next;
        }
        else
        {
            tmp1=headA;
            tmp2=tmp2->next;
        }

    }
    return tmp2;
}

/*
int getLength(struct ListNode *head) {
    int length = 0;
    while (head) {
        length++;
        head = head->next;
    }
    return length;
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if (!headA || !headB)
        return NULL;

    // Get lengths and tails of both lists
    int lenA = getLength(headA);
    int lenB = getLength(headB);
    struct ListNode *tailA = headA;
    struct ListNode *tailB = headB;
    while (tailA->next)
        tailA = tailA->next;
    while (tailB->next)
        tailB = tailB->next;

    // If tails are different, no intersection
    if (tailA != tailB)
        return NULL;

    // Move the pointer of the longer list to the same starting point as the shorter list
    struct ListNode *currentA = headA;
    struct ListNode *currentB = headB;
    int diff = abs(lenA - lenB);
    if (lenA > lenB) {
        for (int i = 0; i < diff; i++)
            currentA = currentA->next;
    } else {
        for (int i = 0; i < diff; i++)
            currentB = currentB->next;
    }

    // Traverse both lists in parallel until intersection point is found
    while (currentA && currentB) {
        if (currentA == currentB)
            return currentA;
        currentA = currentA->next;
        currentB = currentB->next;
    }

    return NULL; // No intersection found
}*/
