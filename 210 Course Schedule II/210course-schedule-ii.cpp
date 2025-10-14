class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        queue<int> sett;
        vector<int> count(numCourses);
        int n=prerequisites.size();

        for(int i=0;i<prerequisites.size();i++){
            count[prerequisites[i][1]]++;
        }
        for(int i=0;i<numCourses;i++){
            if(count[i]==0){
                sett.push(i);
            }
        }
        while(!sett.empty()){
            int node=sett.front();
            sett.pop();
            res.push_back(node);
            for(int j=0;j<n;j++){
                if(prerequisites[j][0]==node){
                    count[prerequisites[j][1]]--;
                    if(count[prerequisites[j][1]]==0){
                        sett.push(prerequisites[j][1]);
                    }
                    prerequisites.erase(prerequisites.begin()+j);
                    j--;
                    n--;

                }
            }
        }
        if(prerequisites.size()!=0){
            return {};
        }
        reverse(res.begin(),res.end());
        return res;

    }
};