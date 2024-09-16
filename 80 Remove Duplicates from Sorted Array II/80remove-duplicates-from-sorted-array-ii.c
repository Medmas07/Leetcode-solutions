int removeDuplicates(int* nums, int numsSize) {
    /*int n =numsSize;
    if(n<=2){
            return n;
        }

        int j = 2;
        for(int i=2; i<n; i++){
            if(nums[i] != nums[j-2]){
                nums[j] = nums[i];
                j++;
            }
        }
        return j;*/
    int k = 0;
    //Base case that is true when array is less than size 2.
    if(numsSize <=2)
    {
        k = numsSize;
    }
    else
    {
        int prevprev = nums[0];
        int prev = nums[1];
        k = k + 2;
        for(int i = 2; i < numsSize; i++)
        {
            //If item is tripple duplicate.
           /* if( (prevprev == nums[i]) && (prev == nums[i]) )
            {
                prevprev = prev;
                prev = nums[i];
            }*/
            //If it is not a tripple duplicate.
            if(prevprev!=  nums[i] || prev !=nums[i])
            {
                prevprev = prev;
                prev = nums[i];
                nums[k] = nums[i];
                k = k + 1;
            }
        }

    }
    
    return k;
}