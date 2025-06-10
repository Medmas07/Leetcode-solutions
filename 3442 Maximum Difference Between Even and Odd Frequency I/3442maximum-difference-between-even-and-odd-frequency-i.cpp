class Solution {
public:
    int maxDifference(string s) {
        map<char,int> dict;
        
        for(int i=0;i<s.size();i++){
            dict[s[i]]++;
            
        }
        int min=101;
        int max=0;
        for(int i=0;i<s.size();i++){
            if(dict[s[i]]>max && dict[s[i]]%2==1){
                max=dict[s[i]];
            }
            if(dict[s[i]]<min && dict[s[i]]%2==0){
                min=dict[s[i]];
            }
        }
        return max-min;
        
   }
};