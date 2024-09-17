/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/*
char** uncommonFromSentences(char* s1, char* s2, int* returnSize) {
    int n=0,l1=strlen(s1),l2=strlen(s2);
    for(int i=0;i<l1;i++)
    {
        if(l1[i]==' ')
            n++;
    }
    n++;
    for(int i=0;i<l2;i++)
    {
        if(l2[i]==' ')
            n++;
    }
    n++;
    int*t=malloc(sizeof(int)*n);
    
    
}*/
typedef struct {
    char* word;
    int count1; // Count in the first sentence
    int count2; // Count in the second sentence
} WordCount;

// Helper function to add a word to the dictionary
void addWord(WordCount* dict, int* size, const char* word, int sentenceNumber) {
    for (int i = 0; i < *size; i++) {
        if (strcmp(dict[i].word, word) == 0) {
            if (sentenceNumber == 1) dict[i].count1++;
            if (sentenceNumber == 2) dict[i].count2++;
            return;
        }
    }
    // Add new word
    dict[*size].word = strdup(word);
    dict[*size].count1 = (sentenceNumber == 1) ? 1 : 0;
    dict[*size].count2 = (sentenceNumber == 2) ? 1 : 0;
    (*size)++;
}

// Tokenize a sentence and count words
void tokenizeAndCount(char* sentence, WordCount* dict, int* size, int sentenceNumber) {
    char* token = strtok(sentence, " ");
    while (token != NULL) {
        addWord(dict, size, token, sentenceNumber);
        token = strtok(NULL, " ");
    }
}

// Compare word counts and collect uncommon words
char** uncommonFromSentences(char* s1, char* s2, int* returnSize) {
    WordCount dict[2000]; // Adjust size as needed
    int size = 0;
    
    // Tokenize and count words from both sentences
    tokenizeAndCount(s1, dict, &size, 1);
    tokenizeAndCount(s2, dict, &size, 2);

    // Allocate memory for result
    char** result = malloc(size * sizeof(char*));
    *returnSize = 0;
    
    // Collect uncommon words
    for (int i = 0; i < size; i++) {
        if ((dict[i].count1 == 1 && dict[i].count2 == 0) ||
            (dict[i].count1 == 0 && dict[i].count2 == 1)) {
            result[*returnSize] = dict[i].word;
            (*returnSize)++;
        } else {
            free(dict[i].word); // Free words that are not uncommon
        }
    }
    
    // Reallocate memory to fit the result size
    result = realloc(result, (*returnSize) * sizeof(char*));
    
    return result;
}