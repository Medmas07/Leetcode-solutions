class Solution {
public:
    bool anagram(string a, string b){
        if(a.size()!=b.size())return false;
        vector<int> alpha(26);
        vector<int> alp(26);
        for(int i=0;i<a.size();i++){
            alpha[a[i]-'a']++;
            alp[b[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(alpha[i]!=alp[i])return false;
        }
        return true;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> res;
        res.push_back(words[0]);
        int n=words.size();
        for(int i=1;i<n;i++){
            if(anagram(words[i-1],words[i])){
                continue;
            }else{
                res.push_back(words[i]);
            }
        }
        return res;
    }
};