/*double myPow(double x, int n) {
    if(n==0)
    return 1;
    else if(x==0)
    return 0;
    else if(n>0)
    return x*myPow(x,n-1);
    else
    return (1/x)*myPow(x,n+1);
}*/
double myPow(double x, int n) {
    if(n==0)
    return 1;
    else if(n==1)
    return x;
    if(n==-1)
    return(1/x);
    double half=myPow(x,n/2);
    if(n%2==0)
    return half*half;
    else if(n>0)
    return half*half*x;
    else 
    return half*half*(1/x);
}