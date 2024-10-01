bool canArrange(int* arr, int arrSize, int k) {

    /*int s=0,m=0,prov=0;
    for(int i=0;i<arrSize;i++)
    {
        arr[i]=arr[i]%k;
        while(arr[i]<=0)
        {
            arr[i]+=k;
        }
        s+=arr[i];
            
    }
    m=s/(arrSize/2);
    if(k<=m && s%k==0)
        return 1;
    return 0;*/
    int *t=calloc(sizeof(int),k);
    for(int i=0;i<arrSize;i++)
    {
        arr[i]=arr[i]%k;
        while(arr[i]<0)
        {
            arr[i]+=k;
        }
        t[arr[i]]++;
    }
    if(t[0]%2!=0)
    {
        printf("t\n");
        return 0;
    }
    else
    {
        for(int i=1;i<(k/2+k%2);i++)
        {
            //printf("t[%d]=%d  and t[%d]=%d  \n",i,t[i],k-i,t[k-i]);
            if(t[i]<t[k-i])
                t[k-i]-=t[i];
            else if(t[i]>t[k-i])
                t[i]-=t[k-i];
            if(t[i]!=t[k-i])
                return 0;
        }
        return 1;
    }
}