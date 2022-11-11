class Solution {
public:
    int romanToInt(string s) {
        
        unordered_map<char,int>ump{
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };        
        int n=s.size(),total = 0,prev = 0;
        
        for(int i=0;i<n-1;++i){
            
            if(ump[s[i]] < ump[s[i+1]]) total -=ump[s[i]];
            else total +=ump[s[i]];
        }
        
        total +=ump[s[n-1]];
        return total;
    }
};