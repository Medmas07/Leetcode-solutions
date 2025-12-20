class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int res=0;
        set<int> exist;
        for(int i=0;i<strs.size()-1;i++){
            for(int j=0;j<strs[i].size();j++){
                if(strs[i][j]-strs[i+1][j]>0){
                    if (exist.find(j) == exist.end()) {
                        res++;
                        exist.insert(j);
                    }
                }
            }
        }
        return res;
    }
};