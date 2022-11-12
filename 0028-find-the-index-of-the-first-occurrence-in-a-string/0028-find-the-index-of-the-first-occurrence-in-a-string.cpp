class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int n= haystack.size(),m = needle.size();
        
        // for(int i=0;i<n;++i){
        //     if(haystack[i] == )
        // }
        
        for(int i=0;i<n;++i){
            
            if(haystack[i] == needle[0]){
                int j = i,k=i;
                for(i;i<j+m;i++){
                    if(haystack[i] != needle[i-j]) break;
                }
                if(i == j+m) return j;
                
                i = k;
            }
        }
        return -1;
    }
};