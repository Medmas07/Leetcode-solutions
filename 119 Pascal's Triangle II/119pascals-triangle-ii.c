/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
unsigned int c(int n, int k) {
    // Si k > n, il n'y a pas de combinaison possible
    if (k > n) {
        return 0;
    }

    // Optimisation : C(n, k) == C(n, n-k) => calculer le plus petit des deux
    if (k > n - k) {
        k = n - k;
    }

    unsigned long long result = 1;

    // Calcul direct de C(n, k) sans passer par les factorielles complètes
    for (int i = 0; i < k; i++) {
        result *= (n - i);
        result /= (i + 1);  // Diviser immédiatement pour éviter les grands nombres
    }

    return result;
}

int* getRow(int rowIndex, int* returnSize) {
    int*t=calloc(sizeof(int),rowIndex+1);
    *returnSize=rowIndex+1;
    for(int i=0;i<=rowIndex;i++)
    {
        t[i]=c(rowIndex,i);
    }
    return t;
}