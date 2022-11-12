class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        
        int n=a.size(), m = b.size();
        
        int l = m/n ;
        
        string temp = "",temp2 = a;
        
        if(m%n != 0) l++;
        
        for(int i=0;i<l;++i) temp +=a;
        
        a = temp;
        
        n = a.size();
        
        for(int i=0;i<n;++i){
            
            if(a[i] == b[0]){
                
                int j = i,k = i;
                
                for(j;j<k+m;++j){
                    
                    if(a[j] != b[j-k]) break;
                }
                
                if( j == k+m) return l;
                
            }
        }
        
        a +=temp2;
        
        n = a.size();
        
        for(int i=0;i<n;++i){
            
            if(a[i] == b[0]){
                
                int j = i,k = i;
                
                for(j;j<k+m;++j){
                    
                    if(a[j] != b[j-k]) break;
                }
                
                if( j == k+m) return l+1;
                
            }
        }
        return -1;
    }
};