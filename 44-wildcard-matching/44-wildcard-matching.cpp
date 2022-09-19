class Solution {
public:
    bool f(int i,int j,string& s, string& p,vector<vector<int>>&dp){
        if(i <= -1 && j<= -1) return true;
        
        if(j<=-1) return false;
        
        if(i<=-1 && j>=0){
            for(int c=j;c>=0;c--){
                if(p[c] == '*') continue;
                return false;
            }
            return true;
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        bool q=false,a=false;
        
        if(s[i] == p[j]  || p[j] == '?'){
            a=f(i-1,j-1,s,p,dp);
        }
        if(p[j] == '*'){
            for(int k=i;k>=-1;k--){
                 q=f(k,j-1,s,p,dp);
                
                if(q==true) return dp[i][j]=true;
            }
        }
        if(q || a ) return dp[i][j]=true;
        
        return dp[i][j]=false;
    }
    bool isMatch(string s, string p) {
        int n=s.size(),m=p.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return f(n,m,s,p,dp);
    }
};