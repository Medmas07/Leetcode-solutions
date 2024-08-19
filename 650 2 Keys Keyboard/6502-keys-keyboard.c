unsigned int prime(int i)
{
    if(i==2)
        return 1;
    else if(i==1)
        return 1;
    else
    {
        int d=2;
        while(i%d!=0)
            d++;
        return i==d;
        
    }
}
int minSteps(int n) {
    int*t=malloc(sizeof(int)*(n+1));
    t[1]=0;
    for(int i=2;i<n+1;i++)
    {
        if(prime(i))
            t[i]=i;
        else
        {
            int j=i-1;
            while(j!=1 && i%j!=0)
                j--;
            t[i]=t[j]+i/j;
            
        }
    }
    int k=t[n];
    free(t);
    return k;
    
}