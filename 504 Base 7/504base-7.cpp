class Solution {
public:
    string convertToBase7(int num) {
        string res="";
        int tmp=abs(num);
        int a=0;
        if(num==0)return "0";
        
        while(tmp!=0){
            a=tmp%7;
            res=to_string(a)+res;
            tmp=tmp/7;
        }
        if(num<0){
            res='-'+res;
        }
        return res;
    }
};