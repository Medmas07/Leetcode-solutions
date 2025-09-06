class Solution {
public:
    string removeOuterParentheses(string s) {
        string res="";
        int stack=0;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]=='('){
                if(stack>0)res+=s[i];
                stack++;
            }
            if(s[i]==')'){
                stack--;
                if(stack>0)res+=s[i];
            }
            
        }
        return res;
    }
};