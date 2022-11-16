class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n = version1.size(),m= version2.size(),i=0,j=0;
        
        while(i<n || j < m){
            
            string str1="",str2 = "";
            
            while(i<n &&  version1[i] != '.'){
                str1 +=version1[i];
                i++;
            }
            
            while(j<m && version2[j] != '.'){
                str2 +=version2[j];
                j++;
            }
            
            int temp1 = 0,temp2 =0 ;
            
            if(str1.size() != 0) temp1 =  stoi(str1);
            if(str2.size() != 0) temp2 = stoi(str2);
            
             
            
            if(temp1 == temp2){
                i++;
                j++;
                 continue;
            }
            
            
            if(temp1 > temp2) return 1;
            if(temp1 < temp2) return -1;
        }
        return 0;
    }
};