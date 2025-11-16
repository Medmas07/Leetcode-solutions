class Solution {
public:
    int numSub(string s) {
        int MOD=1e9+7;
        long long count=0;
        long long res=0;

        for(char c:s){
            if(c=='1'){
                count++;
            }else{
                res+=(count*(count+1))/2;
                count=0;
            }
        }
        res+=(count*(count+1))/2;

        return res%MOD;
    }
};