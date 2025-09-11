class Solution {
public:
    string sortVowels(string s) {
        string tmp="";
        for(int i=0;i<s.size();i++){
            char c=tolower(s[i]);
            if('a'==c || c=='o' || c=='i' || c=='u' || c=='e'){
                tmp+=s[i];
            }
        }
        sort(tmp.begin(), tmp.end());
        string res;
        int j=0;
        for(int i=0;i<s.size();i++){
            char c=tolower(s[i]);
            if('a'==c || c=='o' || c=='i' || c=='u' || c=='e'){
                res+=tmp[j];
                j++;
            }
            else{
                res+=s[i];
            }
        }
        return res;
    }
};