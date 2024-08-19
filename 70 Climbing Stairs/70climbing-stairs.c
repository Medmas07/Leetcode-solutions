int climbStairs(int n) {
   /* if(n==1)
        return 1;
    else if(n==2)
        return 2;
    else if(n<1)
        return 0;
    else 
        return climbStairs(n-1)+climbStairs(n-2);*/ //time limit exceeded
    if(n==1)
        return 1;
   int*t=malloc(sizeof(int)*(n+1));
    t[1]=1;
    t[2]=2;
    for(int i=3;i<n+1;i++)
    {
        t[i]=t[i-1]+t[i-2];
    }
    int k=t[n];
    free(t);
    return k;
}