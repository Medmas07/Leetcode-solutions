class Solution {
public:
    int totalMoney(int n) {
        int nb_week=n/7;
        int rest_of_days=n%7;
        int i=0;
        int res=0;
        for(i=0;i<nb_week;i++){
            res+=28 + i*7;
        }
        int sum=0;
        for(int j=1;j<=rest_of_days;j++){
            sum+=j;
        }
        res+=sum;
        res+=nb_week*rest_of_days;
        return res;
    }
};