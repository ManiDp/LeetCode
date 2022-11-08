class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int>res(n,-1);
        
        for(int i=0;i<n;++i){
            
            bool a = true;
            
            for(int j = i+1;j<n;++j){
                
                if(nums[i] < nums[j]){
                    
                    res[i] = nums[j];
                    a = false;
                    break;
                } 
            }
            if(a){
                for(int k = 0;k<i;++k){
                    if(nums[k] > nums[i]){
                        res[i] = nums[k];
                        break;
                    }
                }
            }
                
            }
        
        
        return res;
    }
};