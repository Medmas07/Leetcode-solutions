bool wordPattern(char* pattern, char* s) {
    int*alphabet=calloc(sizeof(int),26);
    for(int i=0;i<26;i++)
        alphabet[i]=-1;
     
    int n=0,ls=strlen(s),lp=strlen(pattern);
    for(int i=0;i<ls;i++)
    {
        if(s[i]==' ')
            n++;
    }
    n++;
   // printf("n %d\n",n);
    if(lp!=n)
        return 0;
    char**word=malloc(sizeof(char*)*n);
    int k=0,prec=0;
    for(int i=0;i<n;i++)
    {
        word[i]=malloc(3000);
        
        while(k<ls && s[k]!=' ')
            k++;
        
        strncpy(word[i],s+prec,k-prec);
        word[i][k-prec]='\0';
        //printf("word[%d]=%s\n",i,word[i]);
        k++;
        prec=k;
    }
    for(int i=0;i<lp;i++)
    {
        if(alphabet[pattern[i]-'a']==-1)
        { alphabet[pattern[i]-'a']=i;}
            //printf("der %s\n",word[alphabet[pattern[i]-'a']]);}
        //printf("der %u\n",strcmp(word[alphabet[pattern[i]-'a']],word[i])!=0);
        else
            if(strcmp(word[alphabet[pattern[i]-'a']],word[i])!=0)
                return 0;
    }
    for(int i=0;i<26;i++)
    {
        if(alphabet[i]!=-1)
            for(int j=0;j<26;j++)
            {
                if(j!=i && alphabet[j]!=-1 && strcmp(word[alphabet[j]],word[alphabet[i]])==0)
                    return 0;
            }
    }
    
    return 1;
    
}