class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int m=needle.size();
        
        string str = needle+"$"+haystack;
        
        int n = str.size();
        
        for(int i=m+1;i<n;++i){
            
            if(str[i] == str[0]){
                
                int left =0,right = i,count=0;
                
                while(str[right] != '$' && str[right] == str[left]){
                    count++;
                    right++;
                    left++;
                }
                
                if(count == m) return i-m-1;
            }
        }
        return -1;
    }
};