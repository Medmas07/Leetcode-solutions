#include <set>
#include <iostream>
#include <string>
using namespace std ;
class Solution {
public:
    
    bool isAnagram(string s, string t) {
        std::set<char> mySet; 
        if (s.length()!=t.length()){
            return false;
        }
        for(int i=0;i<s.length();i++){
            mySet.insert(s[i]);
        }
        for (const auto& chara: mySet) {
            if (count(s.begin(), s.end(), chara)!=count(t.begin(), t.end(), chara)){
                return false;
            }
        }


        return true;
    }
};