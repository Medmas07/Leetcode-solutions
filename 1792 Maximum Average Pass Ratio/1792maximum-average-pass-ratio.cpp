class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto gain = [](int pass, int total) -> double {
            return ((double)(pass + 1) / (total + 1)) - ((double)pass / total);
        };
          
        priority_queue<pair<double, pair<int, int>>> pq;
        
        for (auto& c : classes) {
            pq.push({gain(c[0], c[1]), {c[0], c[1]}});
        }

         while (extraStudents--) {
            auto top = pq.top(); pq.pop();
            int pass = top.second.first;
            int total = top.second.second;

            pass += 1;
            total += 1;

            pq.push({gain(pass, total), {pass, total}});
        }

        double res = 0.0;
        while (!pq.empty()) {
            auto [_, p] = pq.top(); pq.pop();
            res += (double)p.first / p.second;
        }

        return res / classes.size();
    }
};