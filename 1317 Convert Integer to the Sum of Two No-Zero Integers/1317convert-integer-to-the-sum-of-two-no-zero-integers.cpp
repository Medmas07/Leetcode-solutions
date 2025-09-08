class Solution {
public:
    bool isNoZeroInteger(int n){
        int x=n;
        while(x!=0){
            if(x%10==0)return false;
            x=x/10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        vector<int> res;
        for(int i=1;i<=n/2;i++){
            if(isNoZeroInteger(i)&&isNoZeroInteger(n-i)){
                res.push_back(i);
                res.push_back(n-i);
                break;
            }
        }
        return res;
    }
};