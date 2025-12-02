class Solution {
public:
    int nCr(int n) { return (n - 1) * n / 2; }
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, int> points_per_line;
        for (int i = 0; i < points.size(); i++) {
            points_per_line[points[i][1]]++;
        }
        long long sum = 0 , ans =0;
        // cout<<points_per_line.size()<<endl;
        for (auto k = points_per_line.begin(); k != points_per_line.end();
             ++k) {

            if (k->second <= 1) {
                continue;
            }
            long long edge=(long long)((long long)k->second * (k->second -1)/2);
            ans+=edge*sum;
            sum+=edge;
            
        }
        return ans % 1000000007;
    }
};