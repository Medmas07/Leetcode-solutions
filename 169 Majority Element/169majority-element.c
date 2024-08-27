int majorityElement(int* nums, int numsSize) {
    /*int cond=numsSize/2;
    int i=0,j=0,k=1;
    for(i;i<numsSize && k<cond;i++)
    {
        if(nums[i]==nums[j] && j!=i )
            k++;
        if(i==numsSize-1)
        {
            j++;
            i=j;
            k=1;
        }
        
    }
    return nums[j];*/
      int candidate = 0;
    int count = 0;

    for (int i = 0; i < numsSize; i++) {
        if (count == 0) {
            candidate = nums[i];
        }
        count += (nums[i] == candidate) ? 1 : -1;
    }

    return candidate;
}