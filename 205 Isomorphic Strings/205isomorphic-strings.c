bool isIsomorphic(char* s, char* t) {
   /* int lt=strlen(t);
    
    for(int i=0;i<lt;i++)
    {int j=0;
        for(j=0;j<i ;j++)
        {
            if((t[j]==t[i] && s[j]!=s[i]) || (s[j]==s[i] && t[j]!=t[i]))
                return 0;
            
        }
        
            
    }
    return 1;*///40/46 testcases
    int*map_s_to_t=calloc(sizeof(int),256);
    int*map_t_to_s=calloc(sizeof(int),256);
    
    for(int i=0;i<strlen(t);i++)
    {
        /*if(map_s_to_t[s[i]]==0)
            map_s_to_t[s[i]]=t[i];
        else if(map_s_to_t[s[i]]!=t[i])
            return 0;
        
        if(map_t_to_s[t[i]]==0)
            map_t_to_s[t[i]]=s[i];
        else if(map_t_to_s[t[i]]!=s[i])
            return 0;*/
        if(map_s_to_t[(unsigned char)s[i]]==0 && map_t_to_s[(unsigned char)t[i]]==0)
        {
            map_s_to_t[(unsigned char)s[i]]=t[i];
            map_t_to_s[(unsigned char)t[i]]=s[i];
        }
        else if(map_s_to_t[(unsigned char)s[i]]!=t[i] || map_t_to_s[(unsigned char)t[i]]!=s[i])
            return 0;
        
    }
    
    return 1;
}