unsigned int nexiste(char c,int n,char*s)
{
   
    int i=0;
    for(i;i<n;i++)
    {
        if(s[i]==c)
            return 0;
    }
    return 1;
}

int lengthOfLongestSubstring(char* s) {
    int l_max=0;
    int l=strlen(s);
    int i=0,j=0;
    while(i<l)
    {
     j=i+1;
       
        while(j<l && nexiste(s[j],j-i,s+i))
        {j++;
         }
      
        
        if((j-i)>l_max)
            l_max=j-i;
        i++;    
    }
    return l_max;
}