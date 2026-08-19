class Solution {
public:
    bool isSafe(int row,int col,vector<string>& board,int n){
        int dupCol=col;
        int dupRow=row;

        while(col>=0 && row>=0){
            if(board[row][col]=='Q') return false;
            row--;
            col--;
        }
        row=dupRow;
        col=dupCol;
        while(col>=0){
            if(board[row][col]=='Q') return false;
            col--;
        }
        col=dupCol;
        while(row<n && col>=0){
            if(board[row][col]=='Q') return false;
            row++;
            col--;
        }
        return true;
    }
    void solve(int col,vector<string>& board,int n,vector<vector<string>>& ans){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(isSafe(row,col,board,n)){
                board[row][col]='Q';
                solve(col+1,board,n,ans);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        string s(n,'.');
        vector<string> board(n);
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        vector<vector<string>> ans;

        solve(0,board,n,ans);

        return ans;
    }
};
