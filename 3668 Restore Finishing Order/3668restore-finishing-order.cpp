class Solution {
public:
    bool exist(int a, vector<int>& friends){
        for(int i=0;i<friends.size();i++){
            if(a==friends[i])return true;
        }
        return false;
    }
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        vector<int> res;
        for(int i=0;i<order.size();i++){
            if(exist(order[i],friends))
            {
                res.push_back(order[i]);
            }
        }
        return res;
    }
};