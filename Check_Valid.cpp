class Solution {
public:
    bool issafe(vector<vector<char>>& board, int x, int y, char c)
    {
        int rowblock=(x/3)*3; int colblock=(y/3)*3;
        int row=x;
        int col=y;
        //we will simultaneously check the row, column and block if it already contains the character c in the below for loop
        for(int i=0; i<9; i++)
        {
            if( (i!=y) && board[row][i]==c || (i!=x) && board[i][col]==c || (rowblock+i/3 !=x && colblock+i%3!=y) && board[rowblock+i/3][colblock+i%3]==c)
                return false;
        }
        return true;
    }   
    
    bool isValidSudoku(vector<vector<char>>& board){
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                if(board[i][j]!='.')
                {
                    if(!issafe(board, i, j, board[i][j]))
                    return false;
                }
            }
        }
        
        return true;
    }
    
};
