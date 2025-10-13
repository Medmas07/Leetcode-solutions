class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> count(numCourses, 0);
        queue<int> pre;

        for (int i = 0; i < (int)prerequisites.size(); i++) {
            int a = prerequisites[i][0], b = prerequisites[i][1];
            if (a == b) return false;          
            count[a]++;                         
        }

        for (int i = 0; i < numCourses; i++)
            if (count[i] == 0) pre.push(i);

        int processed = 0;

        while (!pre.empty()) {
            int node = pre.front(); pre.pop();
            processed++;

            int i = 0;
            int n = (int)prerequisites.size();
            while (i < n) {
                int a = prerequisites[i][0];
                int b = prerequisites[i][1];

                if (b == node) { 
                    if (count[a] > 0) {
                        count[a]--;            
                        if (count[a] == 0) pre.push(a);
                    }
                    prerequisites[i] = prerequisites[n-1];
                    prerequisites.pop_back();
                    n--;
                } else {
                    i++; 
                }
            }
        }

        return processed == numCourses;
    }
};
