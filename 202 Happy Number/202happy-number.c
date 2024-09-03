bool existe(int*t,int l, int a)
{int i=0;
    while(i<l && t[i]!=a)
        i++;
 
 return i==l;
}

bool isHappy(int n) {
    int l=1,s=0;
    int*t=malloc(sizeof(int)*l);
    t[0]=n;
    while(n!=1 && existe(t,l-1,n))
    {
        while(n!=0)
        {
            s+=(n%10)*(n%10);
            n=n/10;
        }
       // printf("%d\n",s);
        l++;
        t= realloc(t,l*4);
        t[l-1]=s;
        
        
        
        n=s;
        s=0;
    }
    return n==1;
}