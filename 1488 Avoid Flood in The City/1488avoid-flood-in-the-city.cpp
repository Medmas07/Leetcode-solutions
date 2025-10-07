class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        vector<int> ans;
        unordered_set<int> full_lake;  
        set<int> dry_days;             
        unordered_map<int, int> lake_to_day;

        for(int i=0;i<rains.size();i++){
            if(rains[i]!=0){
                int lake=rains[i];

                if(full_lake.find(lake) != full_lake.end()){
                    auto it=dry_days.upper_bound(lake_to_day[lake]);
                    if(it == dry_days.end()){
                        return {};
                    }
                    ans[*it]=lake;
                    dry_days.erase(it);
                }

                lake_to_day[lake]=i;
                full_lake.insert(rains[i]);
                ans.push_back(-1);

            }else{
                ans.push_back(1);
                dry_days.insert(i);
            }
        }
        return ans;


    }
};