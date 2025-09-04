class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int i_max = 0;
        double max_diag = 0;
        int max_area = 0;
        for (int i = 0; i < dimensions.size(); i++) {
            double diag=sqrt(dimensions[i][0]*dimensions[i][0] + dimensions[i][1]*dimensions[i][1]);
            int area=dimensions[i][0]*dimensions[i][1];
            if(max_diag<diag){
                max_diag = diag;
                i_max = i;
                max_area = area;
            }

            if(max_diag==diag && max_area<area){
                i_max = i;
                max_area = area;
            }
        }
        return max_area;
    }
};