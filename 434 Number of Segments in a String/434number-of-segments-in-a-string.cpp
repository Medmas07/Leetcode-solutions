class Solution {
public:
    int countSegments(string s) {
        
        int j=0;
        while(j<s.length() && s[j]==' '){
            j++;
        }
        if(j==s.length())return 0;
        int ans=0;
        for(int i=j ;i<s.length();i++){
            if (s[i]==' ' && i+1<s.length() && s[i+1]!=' '){
                ans++;
            }
        }
        return ans+1;
    }
};