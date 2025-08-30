class Solution {
public:
    bool isValidRow(vector<char>& col){
        unordered_map<char, int> verif;
        for(int i=0;i<col.size();i++){
            if (isdigit(col[i])) {
                if (verif[col[i]] != 0) {
                    return false;
                }
                verif[col[i]]++;
            }
        }
        return true ;
    }

public:
    bool isValidBox(vector<vector<char>>& board, int a , int b){
        unordered_map<char, int> verif;
        for(int i=a;i-a<3;i++){
            for(int j=b;j-b<3;j++){
                if (isdigit(board[i][j])) {
                if (verif[board[i][j]] != 0) {
                    return false;
                }
                verif[board[i][j]]++;
            }
            }
        }
        return true ;
    }

public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            if(!(isValidRow(board[i]))){
                return false;
            } 
        }
        for(int i=0;i<9;i++){
            unordered_map<char, int> verif;
            for(int j=0;j<9;j++){
                if (isdigit(board[j][i])) {
                    if (verif[board[j][i]] != 0) {
                        return false;
                    }
                    verif[board[j][i]]++;
                }
            }
            
        }
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                if(!(isValidBox(board,i,j)))
                {
                    return false;
                }
            }
        }
        return true;

    }
};