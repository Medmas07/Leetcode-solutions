class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double max = 0;
        int n=points.size();
        for (int i = 0; i < n-2; i++) {
            for (int j = i + 1; j < n-1; j++) {
                for (int k = j + 1; k < n; k++) {
                    int x_a=points[i][0];
                    int y_a=points[i][1];
                    int x_b=points[j][0];
                    int y_b=points[j][1];
                    int x_c=points[k][0];
                    int y_c=points[k][1];
                    double tmp =
                        (double)(0.5 * abs((x_b-x_a)*(y_c-y_a)-(x_c-x_a)*(y_b-y_a)));
                    if(tmp>max){
                        max=tmp;
                    }

                }
            }
        }
        return max;
    }
};