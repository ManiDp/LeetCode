class Solution {
public:
    int myAtoi(string s) {
        
        int n = s.size(),sign =1,i=0;
        
        long long int base =0;
        
       
          
            while(s[i] == ' ') {i++;}
            
            if(s[i] == '-' || s[i] == '+'){
                sign = 1-2*(s[i++] == '-');
            }
            
            while(s[i]-'0' >= 0 && s[i]-'0' < 10){
                
                 
                
                base = base*10+s[i]-'0';
                i++;
                cout<<base<<endl;
                if(base >= INT_MAX){
                    if(sign == 1 ) return INT_MAX;
                    else{
                        break;
                    };
                }
            }
            
            base = sign*base;
            // cout<<base<<endl;
            // if(base >= INT_MAX) return INT_MAX;
            if(base <= INT_MIN) return INT_MIN;
            
            return base;
            
        
        
        
    }
};