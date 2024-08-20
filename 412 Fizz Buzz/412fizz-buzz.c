/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** fizzBuzz(int n, int* returnSize) {
    char**ts=malloc(sizeof(char*)*n);
    for(int i=0;i<n;i++)
    {
        ts[i]=malloc(sizeof(char)*9);
        if((i+1)%3==0 && (i+1)%5==0)
            strcpy(ts[i],"FizzBuzz");
        else if((i+1)%3==0)
            strcpy(ts[i],"Fizz");
        else if((i+1)%5==0)
            strcpy(ts[i],"Buzz");
        else
            sprintf(ts[i],"%d",i+1);
       // printf("%s\n",ts[i]);
    }
    *returnSize=n;
    return ts;
}