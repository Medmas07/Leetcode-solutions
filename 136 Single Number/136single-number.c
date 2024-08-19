int singleNumber(int* nums, int numsSize) {
    
    int k=0,j=0;
    while(j<numsSize && k<numsSize)
    {
        if(nums[k]==nums[j]&& (j!=k) )
        {j++;k=-1;}
     
        k++;
     
    }
    return nums[j];
}