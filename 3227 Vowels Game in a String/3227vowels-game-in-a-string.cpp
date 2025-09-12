class Solution {
public:
    bool doesAliceWin(string s) {
        int a=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                return true;
                
            }
            
        }

        return false;


    }
};