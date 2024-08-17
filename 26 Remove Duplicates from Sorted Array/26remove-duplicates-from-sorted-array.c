int removeDuplicates(int* nums, int numsSize) {
    for(int k=0; k<numsSize-1; k++)
    {
        if (nums[k]==nums[k+1])
        {
            for(int j=k;j<numsSize-1;j++)
            {
                nums[j]=nums[j+1];
            }
            k--;numsSize--;
        }
    }
    return numsSize;
}