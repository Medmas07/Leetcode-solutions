class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int res = 0;
        int word_number = 0;
        int i = 0;
        int n = sentence.size();
        int m = searchWord.size();
        if (n - m < 0)
            return -1;
        int start = 0;
        
            string tmp = sentence.substr(start, m);
            // cout<<tmp<<endl;
            if (tmp == searchWord) {
                res = word_number;
                return 1;
            }
        

        // cout<<n-m<<endl;

        for (i = 0; i < n - m; i++) {
            if (sentence[i] == ' ') {
                int start = i + 1;
                word_number++;
                if (start + searchWord.size() <= sentence.size()) {
                    string tmp = sentence.substr(start, searchWord.size());
                    // cout<<tmp<<endl;
                    if (tmp == searchWord) {
                        res = word_number;
                        break;
                    }
                }
            }
        }
        if (i == sentence.size() - searchWord.size()) {
            return -1;
        }
        // cout<<word_number<<endl;
        return res + 1;
    }
};