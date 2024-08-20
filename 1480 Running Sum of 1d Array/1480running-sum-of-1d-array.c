

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* runningSum(int* nums, int numsSize, int* returnSize){
int* t=malloc(sizeof(int)*numsSize);
    *returnSize=numsSize;
    for(int i=0;i<numsSize;i++)
    {
        if(i==0)
            t[i]=nums[i];
        else
        t[i]=nums[i]+t[i-1];
    }
    return t;
}