class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>&visited,vector<vector<char>>& grid,int n,int m){
        
        if(i<0 || i>=n || j<0 || j>=m || visited[i][j] || grid[i][j] != '1') return;
        
        visited[i][j] =1;
        
        dfs(i,j+1,visited,grid,n,m);
        dfs(i,j-1,visited,grid,n,m);
        dfs(i+1,j,visited,grid,n,m);
        dfs(i-1,j,visited,grid,n,m);
    }
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size(),m = grid[0].size(),count = 0;
        
        vector<vector<int>>visited(n,vector<int>(m,0));
        
        for(int i=0;i<n;++i){
            for(int j =0;j<m;++j){
                if(!visited[i][j] && grid[i][j] == '1'){
                    
                    count++;
                    dfs(i,j,visited,grid,n,m);
                    
                }
            }
        }
        return count;
    }
};