class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m=mat.size(),n=mat[0].size();
        if((m==r && n==c)||(r*c!=m*n))return mat;
        vector<vector<int>> res(r,vector<int>(c));
        int k=0;
        int q=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cout<<"["<<k<<"]"<<"["<<q<<"]"<<endl;
                cout<<"r = "<<r<<endl;
                if(k<r && q<c){
                    res[k][q]=mat[i][j];
                    q++;
                }
                if(k<r && q>=c){
                    q=0;
                    k++;
                }                
            }
        }
        return res;

    }
};