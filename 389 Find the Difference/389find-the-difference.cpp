class Solution {
public:
    char findTheDifference(string s, string t) {
        int arr[26]={-1};
        for(int i=0;i<s.length();i++){
            arr[s[i]-'a']++;
        }
        int arr1[26]={-1};
        for(int i=0;i<t.length();i++){
            arr1[t[i]-'a']++;
        }
        for(int i=0;i<t.length();i++){
            if(arr[t[i]-'a']!=arr1[t[i]-'a']){
                return t[i];
            }
        }
        return 'a';
    }
};