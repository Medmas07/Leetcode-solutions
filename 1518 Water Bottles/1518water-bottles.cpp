class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int current_full_bottle=numBottles;
        int current_empty_bottle=0;
        int res=0;
        while(!(current_full_bottle==0 && current_empty_bottle<numExchange)){
            res+=current_full_bottle;
            current_empty_bottle+=current_full_bottle;
            current_full_bottle=(int)current_empty_bottle/numExchange;
            current_empty_bottle=current_empty_bottle%numExchange;
        }
        return res;
    }
};