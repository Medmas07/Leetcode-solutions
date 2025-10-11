class Solution {
public:
    int calculScore(string s){
        int n=s.size();
        int score=0;
        for(int i=0;i<n;i++){
            score+=s[i]-'a'+1;
        }
        return score;
    }
    bool scoreBalance(string s) {
        bool a=false;
        for(int i=1;i<s.size();i++){
            string tmp = s.substr(0,i);
            string tmp1 = s.substr(i);
            if(calculScore(tmp)==calculScore(tmp1)){
                return true;
            }
        }
        return false ;
    }
};