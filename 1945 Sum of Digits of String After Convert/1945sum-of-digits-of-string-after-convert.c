int getLucky(char* s, int k) {
    int l=strlen(s),som=0,p=0;
    char* t=malloc(sizeof(char)*(2*l+1));
    for(int i=0;i<l;i++)
    {
        p=(int)s[i]-96;
        som+=(p/10+p%10);
    }
    int som2=0;
    for(int i=0;i<k-1;i++)
    {
        while(som!=0)
        {som2+=som%10;
        som=som/10;}
        som=som2;
        som2=0;
        
    }
    return som;
    
}