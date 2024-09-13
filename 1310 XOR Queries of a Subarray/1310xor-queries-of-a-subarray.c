/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* xorQueries(int* arr, int arrSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
   /* int*answers=calloc(sizeof(int),queriesSize);
    *returnSize=queriesSize;
    for(int i=0;i<queriesSize;i++)
    {
        for(int j=queries[i][0];j<=queries[i][1];j++)
        {
            answers[i]^=arr[j];
        }
    }
    return answers;*///41/42 testcases
    int *answers=calloc(sizeof(int),queriesSize);
    *returnSize=queriesSize;
    int *prexor=calloc(sizeof(int),arrSize+1);
    for(int i=0;i<arrSize;i++)
    {
        prexor[i+1]=arr[i]^prexor[i];
    }
    for(int i=0;i<queriesSize;i++)
    {
        answers[i]=prexor[queries[i][1]+1]^prexor[queries[i][0]];
    }
    return answers;
}