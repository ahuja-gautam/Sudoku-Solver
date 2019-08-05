class Solution {
public:
    bool solve(vector<vector<char>>& board)
    {
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                if(board[i][j]=='.')
                {
                    for(char c='1'; c<='9'; c++)
                    {
                        if(issafe(board, i, j, c))
                        {
                            board[i][j]=c;
                            if(solve(board))
                                return true;
                            else        
                                board[i][j]='.';
                        }
                    }
                    return false;
                }
                
            }
        }
        
        return true;
    }
    
    bool issafe(vector<vector<char>>& board, int x, int y, char c)
    {
        int rowblock=(x/3)*3; int colblock=(y/3)*3;
        int row=x;
        int col=y;
        //we will simultaneously check the row, column and block if it already contains the character c in the below for loop
        for(int i=0; i<9; i++)
        {
            if(board[row][i]==c || board[i][col]==c ||board[rowblock+i/3][colblock+i%3]==c)
                return false;
        }
        return true;
    }
      
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    } 
};
