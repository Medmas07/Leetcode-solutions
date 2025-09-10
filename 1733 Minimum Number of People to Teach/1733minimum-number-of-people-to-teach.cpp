class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();

        vector<unordered_set<int>> userLangs(m);
        for (int i = 0; i < m; ++i) {
            for (int lang : languages[i]) {
                userLangs[i].insert(lang);
            }
        }

        unordered_set<int> needTeach;
        unordered_map<int, int> langCount;

        for (auto& f : friendships) {
            int u = f[0] - 1, v = f[1] - 1;

            bool canCommun=false;
            for (int lang : userLangs[u]) {
                if(userLangs[v].count(lang)){
                    canCommun=true;
                    break;
                }
            }
            if(!canCommun){
                needTeach.insert(u);
                needTeach.insert(v);
            }

           
        }
        for (int user : needTeach) {
            for (int lang : userLangs[user]) {
                langCount[lang]++;
            }
        }

        int maxKnown=0;
        for (auto& [lang, count] : langCount) {
            maxKnown = max(maxKnown, count);
        }

        return needTeach.size() - maxKnown;
    }
};
