class Solution {
public:
    int romanToInt(string s) {
        
        unordered_map<char,int>ump;
        
        ump['I'] = 1;
        ump['V'] = 5;
        ump['X'] = 10;
        ump['L'] = 50;
        ump['C'] = 100;
        ump['D'] = 500;
        ump['M'] = 1000;
        
        int n=s.size(),total = 0,prev = 0;
        
        total +=ump[s[0]];
        prev = ump[s[0]];
        
        for(int i=1;i<n;++i){
            
            total +=ump[s[i]];
            
            if(prev < ump[s[i]]){
                total -= 2*prev;
            }
            
            prev = ump[s[i]];
        }
        
        return total;
    }
};