class Solution {
public:
    
    void dfs(int node,vector<int>&visited,vector<int>adjLs[]){
        
        visited[node]=1;
        
        for(auto it: adjLs[node]){
            if(!visited[it]){
                dfs(it,visited,adjLs);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n= isConnected.size(),cnt = 0;
        
        vector<int>adjLs[n+1],visited(n+1);
        
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                if(isConnected[i-1][j-1] == 1 && i != j){
                    adjLs[j].push_back(i);
                    adjLs[i].push_back(j);
                }
            }
        }
        
        
        for(int i=1;i<=n;++i){
            if(!visited[i]){
                cnt++;
                dfs(i,visited,adjLs);
            }
        }
        
        return cnt;
    }
};