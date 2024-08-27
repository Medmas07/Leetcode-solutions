int mostFrequentEven(int* nums, int numsSize) {
    int min=100000,countprec=0,count=1,b=0;
    for(int i=0;i<numsSize;i++)
    {
        for(int j=i+1;j<numsSize;j++)
        {
            if(nums[i]==nums[j])
                count++;
        }
       
        
        if(((countprec<count) || (countprec==count && nums[i]<min) )&& (nums[i]%2==0))
        {
            min=nums[i];
             countprec=count;
            b=1;
        }
        count=1;
    }
    if(b==0)
        return -1;
    return min;
}