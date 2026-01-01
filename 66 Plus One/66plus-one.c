/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
  if (digits[digitsSize-1]!=9)
  {
      digits[digitsSize-1]+=1;
      *returnSize=digitsSize;
      return digits;
  }
  else
  {digits[digitsSize-1]=0;
   if(digitsSize>=2)
   {int i=digitsSize-2;digits[digitsSize-2]+=1;
      while(digits[i]==10 && i>0 )
      {
          digits[i]=0;
          digits[i-1]++;
          i--;
      }
   *returnSize=digitsSize;}
   if(digits[0]==10 || digitsSize<2)
   {*returnSize=digitsSize+1;
       int*t=calloc(*returnSize,sizeof(int));
    t[0]=1;
    return t;
   }
   else
       return digits;
  }

}