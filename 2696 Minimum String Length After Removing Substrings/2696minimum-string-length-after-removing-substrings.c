int minLength(char * s){
    int l=strlen(s);
    char*ch=malloc(sizeof(char)*(l+1));
    for(int i=0;i<l;i++)
    {
        if((s[i]=='A' && s[i+1]=='B')||(s[i]=='C' && s[i+1]=='D'))
        {
            strncpy(ch,s,i);
            ch[i]='\0';
            strcat(ch,s+i+2);
            strcpy(s,ch);
            l=strlen(ch);            
            i=-1;
        }
    }
    return strlen(s);

}