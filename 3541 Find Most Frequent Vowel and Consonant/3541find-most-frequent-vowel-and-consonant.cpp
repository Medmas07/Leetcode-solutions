class Solution {
public:
    int maxFreqSum(string s) {
        int freq_vowel = 0;
        int freq_cons = 0;
        int freq_maxv = 0;
        int freq_maxc = 0;
        sort(s.begin(), s.end());
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == s[i + 1] &&
                (s[i] == 'o' || s[i] == 'i' || s[i] == 'e' || s[i] == 'a' ||
                 s[i] == 'u')) {
                freq_vowel++;
            } else if (s[i] != s[i + 1] &&
                       (s[i] == 'o' || s[i] == 'i' || s[i] == 'e' ||
                        s[i] == 'a' || s[i] == 'u')) {
                freq_vowel++;
                if (freq_vowel > freq_maxv) {
                    freq_maxv = freq_vowel;
                }
                freq_vowel = 0;
            } else if (s[i] == s[i + 1]) {
                freq_cons++;
            } else {
                freq_cons++;
                if (freq_cons > freq_maxc) {
                    freq_maxc = freq_cons;
                }
                freq_cons = 0;
            }
        }
        return freq_maxv + freq_maxc;
    }
};