class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_map<string,int> m;
        vector<string> n={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        for(int i=0;i<words.size();i++){
            string tmp="";
            for(int j=0;j<words[i].size();j++){
                tmp+=n[words[i][j]-'a'];
            }
            m[tmp]++;
        }
        return m.size();
    }
};