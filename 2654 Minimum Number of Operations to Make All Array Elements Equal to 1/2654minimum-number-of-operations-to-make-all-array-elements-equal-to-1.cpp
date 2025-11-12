class Solution {
private:
    bool no_one_in_vec(vector<int>& tmp){
        int i=0;
        while(i<tmp.size()&& tmp[i]!=1){
            i++;
        }
        return i==tmp.size();
    }
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int count_one = 0;
        for (int x : nums)
            if (x == 1) count_one++;
        if (count_one > 0)
            return n - count_one;
        vector<int> tmp = nums;
        
        int i = 0;
        int res = 0;
       
        int nb_one = 0;
        bool bgcd = 0;
        int op=-1;
        while (tmp.size()>1 && no_one_in_vec(tmp)) {
             vector<int> tmp_gcd;
            for (i = 0; i < tmp.size() - 1; i++) {
                int tt = gcd(tmp[i], tmp[i + 1]);
               /* if (nums[i] == 1) {
                    nb_one++;
                }
                if (tt == 1) {
                    bgcd = 1;
                }*/
                tmp_gcd.push_back(tt);
               
            }
            tmp=tmp_gcd;
             op++;
        }
        if(tmp.size()==1 && tmp[tmp.size()-1]!=1)return -1;


        

        return n+op;
    }
};