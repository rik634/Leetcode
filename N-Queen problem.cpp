// level: Medium
// problem statement:

// brute force:
class Solution {
public:
    bool isSafe(int row, int col, vector<vector<char>>& board, int& n)
    {
        // checking the same row
        for(int i=0;i<col;i++)
        {
            if(board[row][i]=='Q')
            {
                return false;
            }
        }
        // checking upper left diagonal
        for(int i=row,j=col;i>=0 && j>=0; i--,j--)
        {
            if(board[i][j]=='Q')
            {
                return false;
            }
        }

        // checking lower left diagonal
        for(int i=row,j=col; i<n && j>=0; i++,j--)
        {
            if(board[i][j]=='Q')
            {
                return false;
            }
        }
        return true;
    }
    void findPositions(int& n, vector<vector<char>>& board, vector<vector<string>>& res, int col){

        if(col==n)
        {
            vector<string> v;
            for(int i=0;i<n;i++)
            {
                string row(board[i].begin(),board[i].end());
                v.push_back(row);
            }
            res.push_back(v);
            return;
        }
        // try to place the queen on all the rows for current column
        for(int row=0;row<n;row++)
        {
            if(isSafe(row,col,board,n))
            {
                board[row][col]='Q';
                findPositions(n,board,res,col+1);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>> res;
        vector<vector<char>> board(n,vector<char>(n,'.'));
        findPositions(n,board,res,0);
        return res;
    }
};
// time complexity: O(n*(!n)) (trying all the permutation for placing the queen)
// space complexity: O(n*n) + O(n) (recursive stack space)

// optimized
class Solution {
public:
    void findPosition(int col,int& n, vector<vector<string>>& res, vector<vector<char>>& board, vector<int>& leftRow, vector<int>& lowerDiagonal, vector<int>& upperDiagonal)
    {
        if(col==n)
        {
            vector<string> v;
            for(int i=0;i<n;i++)
            {
                string row(board[i].begin(),board[i].end());
                v.push_back(row);
            }
            res.push_back(v);
            return;
        }
        // checking each row if queen can be placed here
        for(int row=0;row<n;row++)
        {
            if(leftRow[row]==0 && lowerDiagonal[col+row]==0 && upperDiagonal[n-1+col-row]==0)
            {
                board[row][col]='Q';
                 leftRow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[n - 1 + col - row] = 1;
                findPosition(col+1,n,res,board,leftRow,lowerDiagonal,upperDiagonal);
                board[row][col]='.';
                 leftRow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[n - 1 + col - row] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>> res;
        vector<vector<char>> board(n,vector<char>(n,'.'));
        vector<int> leftRow(n,0);
        vector<int> lowerDiagonal(2*n-1,0);
        vector<int> upperDiagonal(2*n-1,0);
        findPosition(0,n,res,board,leftRow,lowerDiagonal,upperDiagonal);
        return res;
    }
};
// time complexity: O(!n) + O(k*n*n) = O(!n)
// space complexity: O(n*n) + O(n) (recursive tack) + O(n) (hash space) = O(n*n)
