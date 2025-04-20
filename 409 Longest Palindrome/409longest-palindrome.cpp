class Solution {
public:
    int longestPalindrome(string s) {
        int result=0;
        int letters[56];
        for(int i=0;i<s.length();i++){
            if(0<= s[i]-'a'){
                letters[s[i]-'a']++;
            }else{
                letters[s[i]-'A'+27]++;
            }
        }
        int l=s.length();
        bool imp=false;
        for(int i=0;i<56;i++){
            result+=(letters[i]/2)*2;
            
        
                if(letters[i]%2==1){
                    imp=true;
                }
            
        }
        /*cout<<result<<endl;
        cout<<max_imp<<endl;
        cout<<l<<endl;
        */
            return result+((imp==true)?1:0);
        
    }
};