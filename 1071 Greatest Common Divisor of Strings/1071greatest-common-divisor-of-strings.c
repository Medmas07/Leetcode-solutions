char* gcdOfStrings(char* str1, char* str2) {
    int l1=strlen(str1),l2=strlen(str2);
    int d=1,gcd=0;
    while(d<=((l1<l2)?(l1):(l2)))
    {
        if(l1%d==0 && l2%d==0)
            gcd=d;
        d++;
    }
    char*ch=malloc(sizeof(char)*(gcd+1));
    strncpy(ch,str1,gcd);ch[gcd]='\0';
   // printf("gcd  %d\n",gcd);
    /*d=((l1<l2)?(l2/gcd):(l1/gcd));
    char*tmpmin=(l1<l2)?(str1):(str2);
    char*tmpmax=(l1<l2)?(str2):(str1);*/
    for(int i=0;i<l2;i+=gcd)
    {
        if(strncmp(ch,str2+i,gcd)!=0)
            return "";
    } 
    for(int i=0;i<l1;i+=gcd)
    {
        if(strncmp(ch,str1+i,gcd)!=0)
            return "";
    } 

    return ch;
}