/*bool isMatch(char* s, char* p) {
    if(s=="\0" && p=="\0")
    return 1;
    else if(s[0]=='.' && s[1]=='*')
    return 1;
    else if(s[0]==p[0])
    {
        if(p[1]!='*')
        return isMatch(s+1,p+1);
        else
        {
            while(s[1]!='\0' && s[0]==s[1])
            s=s+1;
            return isMatch(s+1,p+1);
        }
    }
    else if(p[0]=='.')
    return isMatch(s+1,p+1);
    else return 0;
}*/
/*
bool isMatch(char* s, char* p) {
    // printf("string s %s\n",s);
    // printf("string p %s\n",p);
    if (s[0] == '\0' && p[0] == '\0')
        return 1;
     else if (p[0]!='\0' && p[1] == '*' &&   s[0] == '\0')
        return isMatch(s,p+2); 
    else if (p[0] == '\0' || s[0] == '\0')
        return 0;
   
    else if (p[0] == '.' && p[1] == '*') {
        while (s[0] != '\0')
            s = s + 1;
        return isMatch(s, p + 2);
    }
     else if (p[0] != s[0] && p[1] == '*') {
        return isMatch(s, p + 2);
    }
    else if (s[0] == p[0]) {
        if (p[1] != '*')
            return isMatch(s + 1, p + 1);
        else {
             while (s[0] != '\0' && s[0] == s[1])
                 s = s + 1;

            return isMatch(s + 1, p) || isMatch(s + 1, p + 2);
        }
    } 
     else if (p[0] == '.')
        return isMatch(s + 1, p + 1);
    else
        return 0;
}*/
/*
bool isMatch(char *s, char *p) {
    if (*p == '\0') {
        return *s == '\0';
    }

    bool first_match = (*s != '\0') && (*s == *p || *p == '.');

    if (*(p + 1) == '*') {
        return (isMatch(s, p + 2)) || (first_match && isMatch(s + 1, p));
    } else {
        return first_match && isMatch(s + 1, p + 1);
    }
}*/

bool isMatch(char* s, char* p) {
    if (s[0] == '\0' && p[0] == '\0') // Base case: both s and p are empty
        return true;
    else if (p[0] != '\0' &&  p[1] == '*'  ) { // Wildcard '*' case
        if (isMatch(s, p + 2)) // Try zero occurrences of the preceding character
            return true;
        else if ((s[0] != '\0' && (p[0] == '.' || s[0] == p[0]))) // Try one or more occurrences
            return isMatch(s + 1, p);
        else
            return false;
    }
    else if (p[0] == '\0' || s[0] == '\0') // Base case: either s or p is empty
        return false;
    else if (p[0] == '.' || s[0] == p[0]) // Matching characters
        return isMatch(s + 1, p + 1);
    else
        return false;
}
