class Solution {
public:
    bool isVoyel(char c) {
    c = tolower(c); // Convert to lowercase for case insensitivity
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}
    string reverseVowels(string s) {
        int left=0,right=s.length()-1;
        while(left<right){
            if(isVoyel(s[left]) && (isVoyel(s[right]))){
                char t=s[left];
                s[left]=s[right];
                s[right]=t;
                right--;
                left++;
            }
            else if (isVoyel(s[left]) && !(isVoyel(s[right]))){
                right--;
            }
            else if(!(isVoyel(s[left])) && (isVoyel(s[right]))){
                left++;
            }
            else{
                left++;
                right--;
            }
        }
        return s;
    }
};