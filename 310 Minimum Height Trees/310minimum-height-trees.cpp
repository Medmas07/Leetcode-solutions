class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};

        vector<int> count(n, 0);
        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            count[e[0]]++;
            count[e[1]]++;
        }

        queue<int> sett;
        for (int i = 0; i < n; i++) {
            if (count[i] == 1) sett.push(i);
        }

        int m = n; 
        vector<int> res;

        while (m > 2) {   
            int size = sett.size();
            m -= size;
            for (int i = 0; i < size; i++) {
                int node = sett.front();
                sett.pop();
                for (int neighbor : adj[node]) {
                    count[neighbor]--;
                    if (count[neighbor] == 1) {
                        sett.push(neighbor);
                    }
                }
                count[node] = 0; 
            }
        }

        while (!sett.empty()) {
            res.push_back(sett.front());
            sett.pop();
        }

        return res;
    }
};
