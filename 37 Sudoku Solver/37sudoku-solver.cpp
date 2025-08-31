class Solution {
public:
    bool isValid(int i , int j , int val , vector<vector<char>>& board ){
        for(int col=0;col<board.size();col++){
            if(board[col][j]==val)return false;
        }
        for(int col=0;col<board.size();col++){
            if(board[i][col]==val)return false;
        }

        int i_block=i/3*3;
        int j_block=j/3*3;
        for(int row=i_block;row<i_block+3;row++){
            for(int  col=j_block;col<j_block+3;col++){
                if(board[row][col]==val)return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board.size();j++){
                if(board[i][j]=='.'){
                    for(int k=1;k<=9;k++){
                        if(isValid(i,j,k+'0',board)){
                            board[i][j]='0'+k;
                            if(solve(board))return true ;
                            board[i][j]='.';
                        }
                        
                    }
                    return false;
                }
                
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        bool a= solve(board);
    }
};