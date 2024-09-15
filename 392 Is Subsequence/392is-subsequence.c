bool isSubsequence(char* s, char* t) {
  /*  if(t[0]=='\0' && s[0]!='\0')
        return 0;
    else if(s[0]=='\0')
        return 1;
    else if(s[0]==t[0])
        return isSubsequence(s+1,t+1);
    else
        return isSubsequence(s,t+1);*/
    char*t1=t;
    char*s1=s;
    while(t1[0]!='\0' && s1[0]!='\0')
    {
        if(s1[0]==t1[0])
        {
            s1=s1+1;
            t1=t1+1;
        }
        else
            t1=t1+1;
    }
    return strlen(s1)==0;
}