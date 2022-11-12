class Solution {
    int BASE = 1e6;
public:
    int rabin_karp(string source,string target){
        
        int power=1,targetcode = 0,hashcode = 0,m = target.size(),n=source.size();
        
        for(int i=0;i<m;++i){
            
            power = (power*31)%BASE;
        }
        
        for(int i=0;i<m;++i){
            
            targetcode = (targetcode*31 + target[i])%BASE;
        }
        cout<<targetcode<<endl;
        
        for(int i=0;i<n;++i){
            
            hashcode = (hashcode*31 + source[i])%BASE;
            
            if(i<m-1) continue;
            
            if(i>=m){
                hashcode = (hashcode - (source[i-(m)]*power))%BASE;
            }
            if(hashcode<0)
                hashcode+=BASE;
            
            if(hashcode == targetcode){
                if(source.substr(i-(m-1),m) == target) return i-(m-1);
            }
            
            // hashcode = (hashcode - (source[i-(m-1)]*power))%BASE;
            // if(hashcode<0)
            //     hashcode+=BASE;
        }
        
        return -1;
    }
    int repeatedStringMatch(string a, string b) {
        
        if(a == b) return 1;
        
        int count = 0;
        
        string str = "";
        
        while(str.size() < b.size()){
            
            str  +=a;
            count++;
        }
        if(str == b) return count;
        
        if(rabin_karp(str,b) != -1) return count;
        if(rabin_karp(str+a,b) != -1) return count+1;
        
        return -1;
    }
};