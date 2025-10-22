class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<int> res;
        int min_diff=area;
        int t=1;
        for(int i=1;i*i<=area;i++){
            if(area%i==0){
                int a=area/i;
                if(abs(a-i)<min_diff)
                {
                    min_diff=abs(a-i);
                    t=a;
                }
                
            }
        }
        res.push_back(t);
        res.push_back(area/t);
        return res;
    }
};