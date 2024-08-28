

char * mergeAlternately(char * word1, char * word2){
    int l=(strlen(word1)<strlen(word2))?strlen(word1):strlen(word2);
    char*merged=malloc(sizeof(char)*(strlen(word1)+strlen(word2)+1));
    int k=0;
    for(int i=0;i<l;i++)
    {
        merged[k]=word1[i];
        k++;
        merged[k]=word2[i];
        k++;
    } 
    merged[k]='\0';
    if(l==strlen(word1))
        strcat(merged,word2+l);
    else
        strcat(merged,word1+l);
    
    return merged;

}