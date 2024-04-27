typedef struct Node {
    char val;
    struct Node* next;
} Node;

typedef struct Node* stack;
stack empiler(stack p, char v) {
    stack t = malloc(sizeof(Node));
    if (t == NULL)
        exit(1);
    t->val = v;
    t->next = p;
    return t;
}
stack depile(stack p) {
    if (p == NULL)
        return NULL;
    else {
        stack t = p->next;
        free(p);
        return t;
    }
}
bool isValid(char* s) {
    int l = strlen(s);
    stack p = NULL;
    for (int i = 0; i < l; i++) {
        if (i == 0 && (s[i] == ')' || s[i] == ']' || s[i] == '}'))
            return 0;
        /*if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            p = empiler(p, s[i]);*/
        else if ((p != NULL) && ((s[i] == ')' && p->val == '(') ||
                                 (s[i] == '}' && p->val == '{') ||
                                 (s[i] == ']' && p->val == '[')))
            p = depile(p);
        else  p = empiler(p, s[i]);
    }
    return p == NULL;
}