class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> nb_alphabet(26,0);
        for(int i=0;i<s.length();i++){
            nb_alphabet[s[i]-'a']++;
        }
        int index=-1;
        for(int i=0;i<s.length();i++){
            if(nb_alphabet[s[i]-'a']==1){
                return i;
            }
        }
        return -1;
    }
};