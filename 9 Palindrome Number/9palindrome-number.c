#include <string.h>

char* strrev(char* str) {
    int i = 0;
    int j = strlen(str) - 1;
    char temp;

    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }

    return str;
}

bool isPalindrome(int x) {
    if(x<0)
        return 0;
    else
    {
        char ch[12];
        sprintf(ch,"%d",x);
        char ch1[12];strcpy(ch1,ch);
        return strcmp(strrev(ch),ch1)==0;
    }
}