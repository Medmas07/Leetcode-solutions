class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n=bits.size()-1;
        int i=0;
        while(i<n-1){
            if(bits[i]==1){
                i+=2;
            }else{
                i++;
            }
        }
        if(bits.size()-i==1)return true;
        else{
            if(bits[n-1]==0)return true;
        }
        return false;
    }
};