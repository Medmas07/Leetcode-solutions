/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int cmp(const void *b, const void *a) {
    char *num1 = *(char **)a;
    char *num2 = *(char **)b;

   

    int result = strcmp(num1, num2);


    return result > 0 ? -1 : 1; // Sort in descending order
}


int* lexicalOrder(int n, int* returnSize) {
    char** t=malloc(sizeof(char*)*n);
    for(int i=0;i<n;i++)
    {
        t[i]=malloc(6);
        sprintf(t[i],"%d",i+1);
    }
   /* int m=0,j=0;
    for(int i=0;i<n;i++)
    {
        if((t[i][0]-'0')
    }*/
    qsort(t, n, sizeof(char*), cmp);
    /*for(int i=0;i<n;i++)
    {
        printf("s  %s\n",t[i]);
    }*/
    int*r=calloc(sizeof(int),n);
    for(int i=0;i<n;i++)
    {
        sscanf(t[i],"%d",r+i);
        free(t[i]);
    }
    free(t);
    *returnSize=n;
    return r;
}