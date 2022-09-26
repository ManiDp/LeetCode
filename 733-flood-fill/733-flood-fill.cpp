class Solution {
public:
    
    void dfs(int sr,int sc,vector<vector<int>>& image,vector<vector<int>>&visited,int color,int num){
        
        if(sr<0 || sr >=image.size() || sc<0 || sc >= image[0].size() || visited[sr][sc] || image[sr][sc] != num) return;
        
        visited[sr][sc] = 1;
        image[sr][sc] = color;
        
        dfs(sr,sc+1,image,visited,color,num);
         dfs(sr+1,sc,image,visited,color,num);
         dfs(sr,sc-1,image,visited,color,num);
         dfs(sr-1,sc,image,visited,color,num);
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int n=image.size(),m=image[0].size();
        
        vector<vector<int>>visited(n,vector<int>(m,0));
        
        dfs(sr,sc,image,visited,color,image[sr][sc]);
        
        return image;
    }
};