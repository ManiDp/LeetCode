class Solution {
public:
    bool palindrome(int i,int j,string& s){
        
        int i1 = i;
        
        int l = j-i+1;
        
        for(i;i<i1+(l/2);++i){
                if(s[i] != s[j] ) return false;
                j--;
            }
        return true;
    }
    string longestPalindrome(string s) {
        
        int n = s.size(),i1=0,j1=0,lps=1 ;
        
        if(n == 1 || n == 0) return s;
        
        for(int i=0;i<n;i++){
            for(int j=n-1;j>i ;--j){
                
                bool palstr = false;
                
                if(lps < j-i+1)  palstr = palindrome(i,j,s);
                
                if(palstr && (j-i)+1 > lps){
                    i1 = i;
                    j1 = j;
                    lps = j1-i1+1;
                }
            }
        }
        
        return s.substr(i1,lps);
    }
};