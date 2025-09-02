class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        vector<pair<int, int>> pairs;
        int res = 0;
        for (int i = 0; i < points.size(); i++) {
            for (int j = 0; j < points.size(); j++) {
                if (i == j)
                    continue;

                if (points[i][1] <= points[j][1] &&
                    points[i][0] >= points[j][0] ) {
                    bool a = false;
                    for (int k = 0; k < points.size(); k++) {
                        if (k == i || k == j)
                            continue;
                        int x_k = points[k][0], y_k = points[k][1];
                        if (points[i][1] <= y_k && y_k <= points[j][1] &&
                            points[i][0] >= x_k && points[j][0] <= x_k) {
                            a = true;
                            break;
                        }
                    }
                    if(!a)res++;
                }
            }
        }

        return res;
    }
};