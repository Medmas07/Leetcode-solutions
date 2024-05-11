int numTrees(int n) {
    if (n <2)
        return 1;
    int k=0;
    for (int i = 1; i <= n; i++) {
        k+=numTrees(i-1)*numTrees(n-i);
    }
    return k;
}