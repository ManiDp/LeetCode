class Solution
{
    public:
        int minimumMountainRemovals(vector<int> &nums)
        {
            vector<int> dp1(nums.size(), 1), dp2(nums.size(), 1);

            for (int i = 0; i < nums.size(); ++i)
            {
                for (int j = 0; j < i; ++j)
                {
                    if (nums[i] > nums[j] && 1 + dp1[j] > dp1[i]) dp1[i] = 1 + dp1[j];
                }
            }
            
            int k=0; 
            
            for (int i = nums.size()-1; i >= 0; --i)
            {
                for (int j = nums.size()-1; j>i; --j)
                {
                    if (nums[i] > nums[j] && 1 + dp2[j] > dp2[i]) dp2[i] = 1 + dp2[j];
                }
                
               if(dp1[i] > 1 && dp2[i] > 1) k=max(k,dp1[i]+dp2[i] -1);
            }
            
            return nums.size()-k;
        }
    
};