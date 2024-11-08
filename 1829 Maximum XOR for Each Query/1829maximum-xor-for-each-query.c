/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int powi(int a,int b)
{
    int u=1;
    for(int k=0;k<b;k++)
    {
        u*=a;
    }
    return u;
}
int* getMaximumXor(int* nums, int numsSize, int maximumBit, int* returnSize) {
    *returnSize=numsSize;
    int*t=calloc(sizeof(int),numsSize);
    int k=0;
    int n=numsSize,max=(1<<maximumBit)-1,max1=max;

    // for(int i=0;i<numsSize;i++)
    // {
    //     for(int j=0;j<n;j++)
    //     {
    //         max=nums[j]^max;
    //     }
    //     n--;
    //     t[i]=max;
    //     max=max1;
    // }
    for(int i=0;i<numsSize;i++)
    {
        k=nums[i]^k;
        t[numsSize-1-i]=k^max;
    }
  
    
    return t;
}