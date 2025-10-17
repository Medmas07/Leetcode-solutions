class Solution {
public:
    bool detectCapitalUse(string word) {
        bool is_all_minis = false;
        bool tmp = false;
        bool prev = false;
        bool is_first_char_cap = false;
        if ('A' <= word[0] && word[0] <= 'Z')
            is_first_char_cap = true;
        int i = 1;
        while (i<word.size() && 'A' <= word[i] && word[i] <= 'Z') {
            i++;
        }
        int j=1;
        while(j<word.size() && !('A' <= word[j] && word[j] <= 'Z')){
            j++;
        }
        return ((i==word.size() && is_first_char_cap) || j==word.size());
    }
};