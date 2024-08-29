bool isPalindrome(char* s) {
    int l=strlen(s);
    for(int i=0,j=l-1;i<j;i++,j--)
    {
        
        while((!((*(s+i)<=90 && 65<=*(s+i)) || (*(s+i)<=122 && 97<=*(s+i)) || ('0'<=s[i] && s[i]<='9') ))&& i<j)
            i++;
        if(*(s+i)<=90 && 65<=*(s+i))
        { *(s+i)+=32;
            }
        
        while((!((*(s+j)<=90 && 65<=*(s+j)) || (*(s+j)<=122 && 97<=*(s+j)) || ('0'<=s[j] && s[j]<='9') )) && i<j)
            j--;
        if(*(s+j)<=90 && 65<=*(s+j))
            *(s+j)+=32;
        
        if(s[i]!=s[j])
        {
            //printf("s[%d] = %c s[%d]=%c \n",i,s[i],j,s[j]);
            return 0;
        }
            
    }
    return 1;
}