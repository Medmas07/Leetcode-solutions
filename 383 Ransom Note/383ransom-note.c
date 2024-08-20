bool canConstruct(char* ransomNote, char* magazine) {
    int l=strlen(ransomNote),l2=strlen(magazine);
    char*ch=malloc(l2+1);
    for(int i=0;i<l2+1;i++)
    {
        ch[i]=magazine[i];
    }
    for(int i=0;i<l;i++)
    {
        int j=0;
        while(ransomNote[i]!=ch[j] && j<l2)
            j++;
        if(j==l2)
            return false;
        else
        {char* s=ch+j+1;
         char*ch1=malloc(strlen(ch)+1);
        strncpy(ch1,ch,j);
         ch1[j]='\0';
        /* printf("%s`\n",s);
         printf("ch %s \n",ch);*/
        strcat(ch1,s);
         free(ch);l2--;
         ch=ch1;}
    }
    return true;
}