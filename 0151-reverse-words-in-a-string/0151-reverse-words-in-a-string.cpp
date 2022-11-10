class Solution {
public:
    string reverseWords(string s) {
        
        stack<string>st;
        
        string temp ="";
        
        s +=" ";
        
        int n= s.size();
        int j=0;
        for(j=0;j<n;++j){
            if(s[j] == ' ') continue;
            break;
        }
        
        for(int i=j;i<n;++i){
            
            if( temp.size() != 0 && s[i] == ' '){
                 st.push(temp);
                temp = "";
            }else if(s[i] != ' ') temp +=s[i];
        }
        
        string res="";
        
        n=st.size();
        
        for(int i=0;i<n-1;++i){
            string a = st.top();
            if(a[0] ==' ') {
                st.pop();
                continue;
            }
                res +=st.top()+" ";
                st.pop();
            
        }
        
        res +=st.top();
        
        return res;
    }
};