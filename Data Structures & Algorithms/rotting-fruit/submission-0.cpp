class Solution {
public:
    int bfs(int n,int m,vector<vector<int>>& grid,vector<vector<int>>& visited){
        queue<pair<pair<int,int>,int>> q;
        int initialFresh=0;
        int time_taken=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    visited[i][j]=1;
                }
                else{
                    visited[i][j]=0;
                }
                if(grid[i][j]==1){
                    initialFresh++;
                }
            }
        }

        int deltaRow[]={-1,0,1,0};
        int deltaCol[]={0,1,0,-1};

        while(!q.empty()){
            int u=q.front().first.first;
            int v=q.front().first.second;
            int t=q.front().second;

            time_taken=max(time_taken,t);

            q.pop();

            for(int i=0;i<4;i++){
                int nRow=u+deltaRow[i];
                int nCol=v+deltaCol[i];

                if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && visited[nRow][nCol]==0 && 
                grid[nRow][nCol]==1){
                    q.push({{nRow,nCol},t+1});
                    visited[nRow][nCol]=1;
                    initialFresh--;
                }
            }

        }
        if(initialFresh!=0) return -1;
        return time_taken;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> visited(n,vector<int>(m,0));

        return bfs(n,m,grid,visited);
        
        
    }
};
