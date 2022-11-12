class Solution {
public:
   static  bool compare(string& s1,string& s2){
        return s1.size() < s2.size();
    }
    string longestCommonPrefix(vector<string>& strs) {
        
        int n =strs.size();
        string ans; 
        sort(strs.begin(), strs.end());
        string a = strs[0];
        string b = strs[n-1];
        for(int i =0; i< a.size(); i++){
            if(a[i] == b[i]){
                ans += a[i];
            }else break;
        }
        return ans;
    }
};