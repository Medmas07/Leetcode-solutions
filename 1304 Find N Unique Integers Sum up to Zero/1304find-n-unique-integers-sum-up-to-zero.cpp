class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> tab;
        if(n%2==1)tab.push_back(0);
        for(int i=1;i<=(int)(n/2);i++){
            tab.push_back(i);
            tab.push_back(-i);
        }
        return tab;
    }
};