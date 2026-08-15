class Solution {
public:
    bool dfs(int index,int i,int j,vector<vector<char>>& board, string word){
        if(index==word.length()) return true;
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size()) return false;
        if(board[i][j]!=word[index]) return false;

        char ch=board[i][j];
        board[i][j]='#';

        bool found= dfs(index+1,i-1,j,board,word)||
                    dfs(index+1,i,j+1,board,word)||
                    dfs(index+1,i+1,j,board,word)||
                    dfs(index+1,i,j-1,board,word);
        board[i][j]=ch;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(dfs(0,i,j,board,word)) return true;
            }
        }
        return false;
    }
};
