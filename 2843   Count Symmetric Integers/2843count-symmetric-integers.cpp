#include<string>
class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans=0;
        for(int i=low;i<=high;i++){
            
            string d = to_string(i);
            int s1=0;
            int s2=0;
           // cout<<d<<endl;
            if(d.length()%2==1){
                continue;
            }
            for(int j=0;j<(d.length()/2);j++){
                s1+=d[j];
                s2+=d[(d.length()/2)+j];
            }
            if(s1==s2){
                ans++;
            }
            
        }
        return ans;
    }
    
};