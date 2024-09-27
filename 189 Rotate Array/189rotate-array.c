void rotate(int* nums, int numsSize, int k) {
   
    /*int x=0;
    for(int i=0;i<k;i++)
    {
        x=nums[numsSize-1];
        for(int j=numsSize-1;j>0;j--)
        {
            nums[j]=nums[j-1];
        }
        nums[0]=x;
            
    }*/
    if(numsSize==k)
        return;
    if(numsSize<k)
        k=k%numsSize;
        
    int*t=malloc(sizeof(int)*k);
    for(int i=numsSize-k;i<numsSize;i++)
    {
        t[i-(numsSize-k)]=nums[i];
        printf("t %d\n",t[i-(numsSize-k)]);
    }
    for(int j=numsSize-1;j>k-1;j--)
        {
            nums[j]=nums[j-k];
        }
    for(int i=0;i<k;i++)
    {
        nums[i]=t[i];
    }
    free(t);
}