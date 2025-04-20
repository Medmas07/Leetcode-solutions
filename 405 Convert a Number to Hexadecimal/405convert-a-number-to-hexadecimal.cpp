class Solution {
public:
    string toHex(int num) {
        if(num==0)return "0";
        unsigned int n=num;
        string  a="0123456789abcdef";
        string hex;
        while(n>0){
            hex=a[n%16]+hex;
            n=n/16;
        }
        return hex;
    }
};