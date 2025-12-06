class Solution {
public:
    string toLowerCase(string s) {
        string res="";
        for(int i=0;i<s.size();i++){
            if('A'<=s[i] && s[i]<='Z'){
                res+=('a'+(s[i]-'A'));
            }else{
                res+=s[i];
            }
        }
        return res;
    }
};