class Solution {
public:
    int maximum69Number (int num) {
        string n=to_string(num);
        int count=0;
        int res=0;
        for(int i=0;i<n.size();i++){
            if(n[i]=='6' && count<1){
                res=res*10+9;
                count++;
            }
            else if(n[i]=='6'){
                res=res*10+6;
            }
            else if(n[i]=='9'){
                res=res*10+9;
            }
        }
        return res;

    }
};