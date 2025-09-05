class Solution {
public:
    int balancedStringSplit(string s) {
        int res=0;
        int a=0;
        
        for(int i=0;i<s.size();i++){
            if(s[i]=='R')res++;
            else if(s[i]=='L')res--;
            if(res==0)a++;
        }

        return a;
    }
};