class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        
        vector<int>check(26,0);
        int n=s.size();
        for(int i=0;i<n;++i){
            
            check[s[i] - 'a']++;
            check[t[i] - 'a']--;
        }
        
        for(int i=0;i<26;++i){
            if(check[i]) return false;
        }
        return true;
    }
};