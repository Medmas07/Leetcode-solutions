class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> res;
        for (int num : nums) {
            res.push_back(num);
            while (res.size() >= 2) {
                int a = res[res.size() - 2];
                int b = res[res.size() - 1];
                int g = gcd(a, b);
                if (g == 1) break; // ils sont coprimes, on garde les deux
                res.pop_back();
                res.pop_back();
                res.push_back(lcm(a, b)); // fusionner
            }
        }
        return res;
    }
};