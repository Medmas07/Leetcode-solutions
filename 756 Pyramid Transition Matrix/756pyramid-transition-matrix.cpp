class Solution {
private:
    unordered_map<string,bool> memo;

    void combo_string(vector<string> usefull, int n, int i,
                      vector<string>& res, string tmp) {
        if (i == n) {
            res.push_back(tmp);
        } else {
            for (int j = 0; j < usefull[i].size(); j++) {
                combo_string(usefull, n, i + 1, res,
                             tmp + usefull[i][j]);
            }
        }
    }

public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        if (bottom.size() == 1) return true;
        if (memo.count(bottom)) return memo[bottom];

        vector<string> next_level;
        vector<string> usefull(bottom.size() - 1, "");

        for (int i = 0; i < bottom.size() - 1; i++) {
            for (int j = 0; j < allowed.size(); j++) {
                if (bottom[i] == allowed[j][0] &&
                    bottom[i + 1] == allowed[j][1]) {
                    usefull[i] += allowed[j][2];
                }
            }
            if (usefull[i].empty()) {
                memo[bottom] = false;
                return false;
            }
        }

        combo_string(usefull, usefull.size(), 0, next_level, "");

        for (int i = 0; i < next_level.size(); i++) {
            if (pyramidTransition(next_level[i], allowed)) {
                memo[bottom] = true;
                return true;
            }
        }

        memo[bottom] = false;
        return false;
    }
};
