bool IsSwap(int a,int b)
{
    int counta=0;
    while(a){
        counta+=a&1;
        a>>=1;
    }
    int countb=0;
    while(b)
    {
        countb+=b&1;
        b>>=1;
    }
    return counta==countb;
}

bool canSortArray(int* nums, int numsSize) {
    bool ok=true;
    int tmp=0;
    do{
        ok=true;
        for(int i=0;i<numsSize-1;i++)
        {
            if(nums[i+1]<nums[i])
            {
                if(IsSwap(nums[i],nums[i+1])){
                 
                    tmp=nums[i];
                    nums[i]=nums[i+1];
                    nums[i+1]=tmp;
                    ok=false;
                }
                else
                {
                    return false;
                }
            }
            
            
        }
        numsSize--;
    }while(!(ok || numsSize==1));
    return true;
    
}