/*bool isPowerOfFour(int n) {
    if((n/4==1 && n%4==0)||(n==1))
    return 1;
    if(n%4!=0 || n==0)
    return 0;
    else
    return isPowerOfFour(n/4);
}*/

bool isPowerOfFour(int n) {
    // Check if n is positive and a power of two
    if (n > 0 && (n & (n - 1)) == 0) {
        // Check if the only set bit is at an even position
        return (n & 0x55555555) != 0;
    }
    return false;
}