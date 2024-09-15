int findTheLongestSubstring(char* s) {
    int*t=calloc(sizeof(int),26);
    int l=strlen(s);
    //a=0,e=1,i=2,o=3,u=4
    t['a'-'a']=1;
    t['e'-'a']=2;
    t['i'-'a']=4;
    t['o'-'a']=8;
    t['u'-'a']=16;
    int*comb=malloc(sizeof(int)*32);
    int maxlen=0;
    for(int i=0;i<32;i++)
        comb[i]=-1;
    int prefiXor=0;
    for(int i=0;i<l;i++)
    {
        prefiXor^=t[s[i]-'a'];
        if(comb[prefiXor]==-1 && prefiXor!=0)
            comb[prefiXor]=i;
        maxlen=(maxlen>(i-comb[prefiXor]))?(maxlen):(i-comb[prefiXor]);
    }
    return maxlen;
}