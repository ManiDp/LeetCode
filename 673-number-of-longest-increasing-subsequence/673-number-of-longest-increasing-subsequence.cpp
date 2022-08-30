class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size(),k=-1,ans = 0;
        
        vector<int>dp(n,1),cut(n,1);
        
        for(int i=0;i<n;++i){
            for(int j=0;j<i;++j){
                
                if(nums[i] > nums[j] && 1+dp[j] > dp[i]){
                    dp[i] = 1+ dp[j];
                    cut[i] = cut[j];
                    
                    
                }else if(nums[i] > nums[j] && 1+dp[j] == dp[i]){
                    cut[i] +=cut[j];
                }
            }
            k=max(k,dp[i]);
        }
        
        for(int i=0;i<n;++i){
            if(k == dp[i]) {
                ans +=cut[i];
            }
            
        }
        
        return ans;
    }
};