/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*
typedef struct ListNode* list;
struct ListNode* reverseList(struct ListNode* head) {
   if(head==NULL || head->next==NULL)
   return head;
   else
    {
       struct ListNode*tmp=reverseList(head->next);
       head->next->next=head;
       head->next=NULL;

       return tmp;
    }


}
unsigned long valeur(list head)
{
   /*if(head == NULL)
   return 0;
   else if (head->next == NULL)
       return head->val;
   else
       return (head->val)+ valeur(head->next)* 10;
   unsigned int s=0;
   list l=reverseList(head);
   while(l!=NULL)
   {
   s=10*s+l->val;l=l->next;


   }
   return s;
}

struct ListNode *newNode(struct ListNode *l,int val) {
   struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
   node->val = val;
   node->next = NULL;
   if(l==NULL)
   return node;
   else
   {
       struct ListNode *tmp=l;
       while(tmp->next!=NULL)
       tmp=tmp->next;
       /*node->next=l;
       return node;
       tmp->next=node;
       return l;

   }
}
*/
/*
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    unsigned long s=valeur(l1)+valeur(l2),m=1;
    list l=NULL;
    if(s==0)
    {
        l=newNode(l,s);
    }
    else
    while(s!=0)
    {
        l=newNode(l,s%10);
        s=(s-s%10)/10;
    }
    return l;
}*/
/*
struct ListNode* newNode(struct ListNode* l, int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    if (l == NULL)
        return node;
    else {
        struct ListNode* tmp = l;
        while (tmp->next != NULL)
            tmp = tmp->next;
        /*node->next=l;
        return node;*//*
        tmp->next = node;
        return l;
    }
}

int longueur(struct ListNode* l) {
    int n = 0;
    while (l != NULL) {
        n++;
        l = l->next;
    }
    return n;
}

long long int powe(int a, int b) {
    if (b==0)
    return 1;
    long int i=a;
    while(b!=1)
    {
        a=a*i;
        b--;

    }
    return a;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* tmp1 = l1;struct ListNode* tmp = NULL;
    struct ListNode* tmp2 = l2;
   // int l = longueur(l1);
   long long int s = 0, a = 0,i=0;

    while (tmp1 != NULL) {
        //l = longueur(tmp1);
        a = (powe(10, i));
        i++;
        s = s + (tmp1->val) * a;
     
        tmp1 = tmp1->next;
    
    }
    i=0;
    while (tmp2 != NULL) {
        //l = longueur(tmp2);
        a = (powe(10, i));
        i++;
        s=s+((tmp2->val)*a);
       // l2=tmp2;
        tmp2=tmp2->next;
        //free(l2);
    }
    if(s==0)
return l1;
    while (s != 0) {
        tmp1 = newNode(tmp1, s % 10);
        s = (s - (s % 10)) / 10;
    }

    return tmp1;
}*/

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* tmp1 = l1;struct ListNode* tmp =NULL;
    struct ListNode* tmp2 = l2;struct ListNode* current = NULL;


 int s =0, a = 0,i=0;

    while ((tmp1 != NULL || tmp2 !=NULL) || a!=0) {
        s=a;
        if(tmp1!=NULL)
        {
            s=s+tmp1->val;
            tmp1=tmp1->next;
        }
        if(tmp2!=NULL)
        {s=s+tmp2->val;
        tmp2=tmp2->next;}
        
        a = s / 10;
        s %= 10;

        struct ListNode* newNode = malloc(sizeof(struct ListNode));
        newNode->val = s;
        newNode->next = NULL;

        if (tmp) {
            tmp->next = newNode;
            tmp = tmp->next;
        } else {
            tmp = newNode;
            current = tmp;
        }
    
    }
    

    return current;
}
