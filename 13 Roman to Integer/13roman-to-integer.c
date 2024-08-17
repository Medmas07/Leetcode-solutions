int conv(char c)
{
    if(c == 'I')
        return 1;
    else if(c=='V')
        return 5;
    else if(c=='X')
        return 10;
    else if(c=='L')
        return 50;
    else if(c=='C')
        return 100;
    else if(c=='D')
        return 500;
    else
        return 1000;
}

int romanToInt(char* s) {
    if (*s=='\0')
        return 0;
    else if(*(s+1)=='\0')
        return conv(s[0]);
    else 
    {
        int x=conv(s[0]);
        int y=conv(s[1]);
        if(x<y)
            return -x+romanToInt(s+1);
        else 
            return x+romanToInt(s+1);
    }
        
}