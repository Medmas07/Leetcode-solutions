int sumdigit(int t)
{int s=0;
    while(t!=0)
    {
        s+=t%10;
        t=t/10;
    }
 return s%2==0;
}
    

int countEven(int num) {
    int t=2,n=0,c=0;
    while(t<=num)
    {
     if(sumdigit(t))
         n++;
    t++;
    }
     return n;
    
}