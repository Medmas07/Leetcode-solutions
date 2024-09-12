

int countConsistentStrings(char * allowed, char ** words, int wordsSize){
  //  int n=0;
    int* t=calloc(sizeof(int),26);
    for(int i=0;i<strlen(allowed);i++)
    {
        t[allowed[i]-(int)'a']++;
    }
    int l=wordsSize;
    for(int i=0;i<l;i++)
    {//printf("str  %s\n",words[i]);
        for(int j=0;j<strlen(words[i]);j++)
        {
            if(t[words[i][j]-(int)'a']==0)
            {
                wordsSize--;
                break;
            }
        }
    // printf("wor %d\n",wordsSize);
    }
    free(t);
    return wordsSize;
}