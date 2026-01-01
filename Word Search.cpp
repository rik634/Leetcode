// level: Medium
// problem statement:  Given an m x n grid of characters board and a string word, return true if the word exists in the grid. 
//The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

// solution:
class Solution {
public:
    vector<int> dx={0,0,1,-1};
    vector<int> dy={1,-1,0,0};
    bool checkWord(int ind,int x, int y, vector<vector<char>>& board, string& word)
    {  
        if( x<0 || x>=board.size() || y<0 || y>=board[0].size() || word[ind]!=board[x][y])
        {
            return false;
        }
        // all words are matched
         if(ind==word.length()-1)
        {
          return true;
        }
       char  temp=board[x][y];
       board[x][y]='#';
        
        for(int i=0;i<4;i++)
        {
            int r = dx[i]+x;
            int c = dy[i]+y;
            if(r>=0 && r<board.size() && c>=0 && c<board[0].size())
            {
                if(checkWord(ind+1,r,c,board,word)){
                    return true;
                }
            }
        }
        board[x][y]=temp;
        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        
        int m = board.size();
        int n = board[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(checkWord(0,i,j,board,word))
                {
                    return true;
                }
            }
        }
        return false;
    }
};
// time complexity: O(m*n*(4^L)) (L=length of word)
// space complexity: O(L) (recursion stack space)
