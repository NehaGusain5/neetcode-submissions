class Solution {
private:
    void dfs(int row,int col,vector<vector<int>>& vis,vector<vector<char>>& grid){
        vis[row][col]=1;
        int n=grid.size();
        int m=grid[0].size();

        vector<int> deltaRow={-1,0,1,0};
        vector<int> deltaCol={0,1,0,-1};
            for(int i=0;i<4;i++){
                int nRow=row+deltaRow[i];
                int nCol=col+deltaCol[i];
                if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && grid[nRow][nCol]=='1' && !vis[nRow][nCol]){
                    dfs(nRow,nCol,vis,grid);
                }
            }
        
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));
        int count=0;

        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(!vis[row][col] && grid[row][col]=='1'){
                    count++;
                    dfs(row,col,vis,grid);
                }
            }
        }
        return count;
    }
};
