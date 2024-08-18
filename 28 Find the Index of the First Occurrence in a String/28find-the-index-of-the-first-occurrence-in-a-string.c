int strStr(char* haystack, char* needle) {
    int l1=strlen(haystack),l2=strlen(needle);
    if(l1<l2)
        return -1;
    else
    {
        int i=0;
        while(*haystack != '\0' && strncmp(haystack,needle,l2)!=0 && i<l1)
        {haystack++;
         i++;}
        if(i<l1)
        return i;
        else return -1;
    }
}