int lengthOfLastWord(char* s) {
    char* ch=s;int i=0,j=0;
    while(*ch!='\0')
    {
        if(*ch==' ' && *(ch+1)!=' '&& *(ch+1)!='\0')
           j=i;
        i++;
        ch++;
    }
    ch=s+j+1;
    while(*ch!=' '&& *ch!='\0')
        ch++;
    if (j==0 && s[j]!=' ')
        return strlen(s)-strlen(ch);
    
    return strlen(s+j+1)-strlen(ch);
}