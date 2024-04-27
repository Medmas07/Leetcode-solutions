
//4ms


int fib(int n){
if(n==0)
return 0;
else if(n==1)
return 1;
else
return fib(n-1)+fib(n-2);
}

//2ms
/*int fib(int n) {
    // Base cases: F(0) = 0, F(1) = 1
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    
    // Initialize an array to store Fibonacci numbers
    int fibo[n + 1];
    fibo[0] = 0;
    fibo[1] = 1;

    // Calculate Fibonacci numbers using dynamic programming
    for (int i = 2; i <= n; i++) {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }
    
    // Return the result for F(n)
    return fibo[n];
}*/

//3ms
/*
int fib(int n) {
    // Base cases: F(0) = 0, F(1) = 1
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    
    // Initialize variables to store the last two Fibonacci numbers
    int prev = 0;
    int curr = 1;

    // Calculate Fibonacci numbers using iteration
    for (int i = 2; i <= n; i++) {
        int next = prev + curr;
        prev = curr;
        curr = next;
    }
    
    // Return the result for F(n)
    return curr;
}*/
