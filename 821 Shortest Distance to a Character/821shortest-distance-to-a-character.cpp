class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> answers(s.size());
        for (int i = 0; i < s.size(); i++) {
            if (i == 0) {
                int j = i;
                while (j < s.size() && c != s[j]) {
                    j++;
                }
                answers[i] = j - i;
                continue;
            } else if (i == s.size() - 1) {
                int k = i;
                while (0 <= k && c != s[k]) {
                    k--;
                }
                answers[i] = i - k;
                continue;
            } else {
                int j = i;
                while (j < s.size() && c != s[j]) {
                    j++;
                }
                int k = i;
                while (0 <= k && c != s[k]) {
                    k--;
                }
                int distRight = (j < s.size())
                                    ? j - i
                                    : s.size(); 
                int distLeft = (k >= 0) ? i - k : s.size();

                answers[i] = (distLeft < distRight) ? distLeft : distRight;
            }
        }
        return answers;
    }
};