char* longestCommonPrefix(char** strs, int strsSize) {
    char* com=malloc(200);
    strcpy(com,strs[0]);
    for(int i=1;i<strsSize;i++)
    {int l=0;
    if(strlen(strs[i])<strlen(com))
    l=strlen(com);
    else 
    l=strlen(strs[i]);
        for(int j=1;j<l+1;j++)
        {
            if (strncmp(com,strs[i],j)!=0)
            {if(j == 1)
                return "";
             else
             {strncpy(com,strs[i],j-1);com[j-1]='\0';break;}
        }
        }          
        
    }return com;
}