class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int res=0;
        vector<int> freq_m(edges.size()+2);
        for(int i=0;i<edges.size();i++){
            freq_m[edges[i][0]]++;
            freq_m[edges[i][1]]++;
        }
        auto max_it = max_element(freq_m.begin(), freq_m.end());

        int index = distance(freq_m.begin(), max_it);
        return index;
    }
};