class Solution {
public:
    string majorityFrequencyGroup(string s) {
        vector<int> freq_c(26);
        for(int i=0;i<s.size();i++){
            freq_c[s[i]-'a']++;
        }
        int m= *max_element(freq_c.begin(),freq_c.end());
        string res="";
        for(int i=1;i<=m;i++){
            string tmp="";
            for(int j=0;j<freq_c.size();j++){
                if(freq_c[j]==i){
                    tmp=tmp+static_cast<char>('a' + j);
                }
            }
            if(tmp.size()>=res.size()){
               res=tmp; 
            }
        }
        return res;
    }
};