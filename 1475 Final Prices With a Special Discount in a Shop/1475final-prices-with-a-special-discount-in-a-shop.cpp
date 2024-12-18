class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int l=prices.size();
        vector<int> answers(l,0);
        
        for(int i=0;i<l;i++){
            int j=0;
            for(j=i+1;j<l;j++)
            {
                if(prices[j]<=prices[i]){
                    answers[i]=prices[i]-prices[j];
                    break;
                }
            }
            if(j==l)
                answers[i]=prices[i];
        }
        return answers;
    }
};