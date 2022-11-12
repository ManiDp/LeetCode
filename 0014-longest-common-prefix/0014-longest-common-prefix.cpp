class Solution {
public:
   static  bool compare(string& s1,string& s2){
        return s1.size() < s2.size();
    }
    string longestCommonPrefix(vector<string>& strs) {
        
        sort(strs.begin(),strs.end(),compare);
        
        int n=strs[0].size(),m = strs.size();
        
        string s="";
        
        for(int i=0;i<n;++i){
            
            for(int j=1;j<m;++j){
                if(strs[0][i] != strs[j][i]) return s;
            }
            s +=strs[0][i];
        }
        return s;
    }
};