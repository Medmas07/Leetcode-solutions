bool isPowerOfTwo(int n) {
    long int m=1;
    while(m<n)
    {
        m=2*m;
    }
    return m==n;
}