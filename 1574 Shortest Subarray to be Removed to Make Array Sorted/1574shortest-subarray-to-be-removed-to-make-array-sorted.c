int findLengthOfShortestSubarray(int* arr, int arrSize) {
    int x=0,b=arrSize-1,k=0;
    // for(b=arrSize-1;b>=1;b/=2)
    // {
    //     while(k+b<arrSize && arr[k]<=arr[k+b])
    //     {
    //         k++;
    //     }
    // }
    // while(k<arrSize-1 && arr[k]<arr[k+1])
    // {
    //     k++;
    // }
    // printf("k= %d \n",k);
    // x=k;
    // while(k<arrSize-1 && arr[k]==arr[k+1])
    //     k++;
    // b=k;
    // return b-x+1;
    // while(k<arrSize-1 && arr[k]>=arr[k+1])
    // {
    //     k++;
    // }
    // printf("k= %d \n",k);
    // if(k-x+1==arrSize || k-x==0)
    //     return k-x;
    // return k-x+1;
     while(0<b && arr[b-1]<=arr[b])
    {
        b--;
    }
     k=b;
    while(x<b && (x==0 || arr[x-1]<=arr[x]))
    {
        while(b<arrSize && arr[x]>arr[b])
            b++;
        
        k=((b-x-1)<k)?(b-x-1):k;
        x++;
    }

   
    return k;
}