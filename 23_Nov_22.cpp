class Solution {
public:
     bool isValid(vector<vector<char>> board, int row, int col,char num){
        for(int i=0;i<9;i++){
            if(i!=col && board[row][i]==num){
                return false;
            }
            if(i!=row && board[i][col]==num){
                return false;
            }
            int nrow = 3*(row/3) + i/3;
            int ncol = 3*(col/3) + i%3;
            if(!(nrow==row && ncol==col) && board[nrow][ncol]==num){
                return false;
            }
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]!='.'){
                    if(!isValid(board,i,j,board[i][j])){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
