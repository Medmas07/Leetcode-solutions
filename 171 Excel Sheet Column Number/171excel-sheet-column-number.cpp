class Solution {
public:
    int titleToNumber(string columnTitle) {
        int s=0;
        // for(int i=columnTitle.length()-1;0<=i;i--)
        // {
        //     s=s*26+((int)columnTitle[i]-(int)'A' +1);
        // }
        for(int i=0;i<columnTitle.length();i++)
        {
            s=s*26+((int)columnTitle[i]-(int)'A' +1);
        }
        return s;
    }
};