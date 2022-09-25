class Solution {
public:
    void bfs(int i,int j,vector<vector<int>>&visited,vector<vector<char>>& grid,int n,int m){
        visited[i][j] =1;
        queue<pair<int,int>>q;
        
        q.push({i,j});
        
        while(!q.empty()){
            
            int row = q.front().first;
            int col = q.front().second;
            
            q.pop();
            
            for(int delrow = 0 ;delrow < 1 ;delrow++){
                for(int delcol = -1;delcol <=1 ;delcol++){
                    
                    int nrow = row+delrow;
                    int ncol = col+delcol;
                    
                    if(nrow>=0 && nrow<n && ncol >= 0 && ncol <m 
                       && !visited[nrow][ncol] && grid[nrow][ncol] == '1'){
                        q.push({nrow,ncol});
                        visited[nrow][ncol]=1;
                    }
                }
            }
            
            int nrow = row-1;
                    int ncol = col;
                    
                if(nrow>=0 && nrow<n && ncol >= 0 && ncol <m 
                       && !visited[nrow][ncol] && grid[nrow][ncol] == '1'){
                    q.push({nrow,ncol});
                    visited[nrow][ncol]=1;
            }
            
             nrow = row+1;
           
                    
                if(nrow>=0 && nrow<n && ncol >= 0 && ncol <m 
                       && !visited[nrow][ncol] && grid[nrow][ncol] == '1'){
                    q.push({nrow,ncol});
                    visited[nrow][ncol]=1;
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size(),m = grid[0].size(),count = 0;
        
        vector<vector<int>>visited(n,vector<int>(m,0));
        
        for(int i=0;i<n;++i){
            for(int j =0;j<m;++j){
                if(!visited[i][j] && grid[i][j] == '1'){
                    
                    count++;
                    bfs(i,j,visited,grid,n,m);
                    
                }
            }
        }
        return count;
    }
};