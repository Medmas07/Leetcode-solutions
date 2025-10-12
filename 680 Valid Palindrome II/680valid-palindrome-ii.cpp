class Solution {
public:
    bool isPalind(int left , int right , const string& s){
        while(left<right){
            if(s[left]!=s[right])return false;
            left++;
            right--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int left=0;
        int right=s.size()-1;
        while(left<right){
            if(s[left]!=s[right]){
                return isPalind(left+1,right,s)||isPalind(left,right-1,s);
            }
            left++;
            right--;
        }
        return true;
    }
};