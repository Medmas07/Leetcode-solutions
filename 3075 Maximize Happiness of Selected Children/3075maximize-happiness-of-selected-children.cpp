class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long res=0;
        sort(happiness.begin(),happiness.end(),greater<int>());
        for(int i=0;i<happiness.size();i++){
            if(happiness[i]-i>=0)
            happiness[i]-=i;
            else
            {
                happiness[i]=0;
            }
            //cout<<happiness[i]<<endl;
        }
        int j=0;
        while(j<k){
            res+=happiness[j];
            j++;
        }
        return res;
    }
};