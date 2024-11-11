/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    int**t=malloc(sizeof(int*)*numRows);
    *returnSize=numRows;
    *returnColumnSizes=(int*)calloc(sizeof(int),numRows);
    for(int i=0;i<numRows;i++)
    {
        (*returnColumnSizes)[i]=i+1;
    }
    for(int i=0;i<numRows;i++)
    {
        t[i]=(int*)calloc(sizeof(int),(*returnColumnSizes)[i]);
        t[i][0]=1;
        t[i][(*returnColumnSizes)[i]-1]=1;
        if(i>1)
        {
            for(int j=1;j<(*returnColumnSizes)[i]-1;j++)
            {
                t[i][j]=t[i-1][j]+t[i-1][j-1];
            }
        }
    }
    return t;
}