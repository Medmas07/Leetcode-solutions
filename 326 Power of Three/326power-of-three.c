bool isPowerOfThree(int n) {
    long long int m=1;
    while(m<n)
    m=3*m;
    return m==n;
    
}