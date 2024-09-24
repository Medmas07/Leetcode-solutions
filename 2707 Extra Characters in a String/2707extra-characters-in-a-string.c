
#define MAX_LENGTH 1001
#define DICTIONARY_SIZE 100
bool inDictionary(const char *word, char **dictionary, int dictionarySize) {
    for (int i = 0; i < dictionarySize; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return true;
        }
    }
    return false;
}

int minExtraChar(char * s, char ** dictionary, int dictionarySize){
  
    int n = strlen(s);
    int *memo = (int *)calloc(n + 1, sizeof(int));
    for (int i = 0; i <= n; i++) {
        memo[i] = -1; // Initialize memoization array with -1
    }

    // Dynamic programming function
    int dp(int start) {
        if (start == n) {
            return 0; // Base case: no extra characters left
        }
        if (memo[start] != -1) {
            return memo[start]; // Return cached result
        }

        // Count this character as an extra character
        int ans = dp(start + 1) + 1;
        
        // Check all possible substrings starting from 'start'
        for (int end = start; end < n; end++) {
            char curr[MAX_LENGTH];
            strncpy(curr, s + start, end - start + 1);
            curr[end - start + 1] = '\0'; // Null-terminate the substring

            if (inDictionary(curr, dictionary, dictionarySize)) {
                if(end+1 != n)
                    ans = ans < memo[end + 1] ? ans : memo[end + 1]; // Minimize extra characters
                else
                    ans=0;
            }
        }

        return memo[start] = ans; // Store result in memo
    }
    

    int result = dp(0); // Start from the beginning of the string
    for(int i=0;i<=n;i++)
    {
        printf("t[%d]=%d\n",i,memo[i]);
    }
    free(memo); // Clean up allocated memory
    return result;
}