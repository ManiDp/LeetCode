class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int leftmax=-1,rightmax=height[n-1],res=0,i=0,j=height.size()-1;
        
        while(i<j){
            
            if(height[i] <= height[j]){
                if(leftmax <= height[i]) leftmax = height[i];
                else res +=leftmax - height[i];
                
                i++;
            }else{
                if(rightmax <= height[j]) rightmax=height[j];
                else res +=rightmax - height[j];
                
                j--;
            }
        }
        
        return res;
    }
};