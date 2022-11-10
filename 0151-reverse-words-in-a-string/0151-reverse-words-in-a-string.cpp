class Solution {
public:
    string reverseWords(string s) {
        
        string temp="",ans="";
        
        int n=s.size();
        
        for(int i = n-1;i>=0;i--){
            if(temp.size() == 0 && s[i] == ' ') continue;
            
            if(s[i] == ' '){
                reverse(temp.begin(),temp.end());
                ans +=temp+" ";
                temp = "";
                continue;
            }
            
            temp +=s[i];
            
        }
        reverse(temp.begin(),temp.end());
        if(temp.size() != 0) ans +=temp+" ";
        n=ans.size();
        return ans.substr(0,n-1);        
        
    }
};