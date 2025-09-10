class Solution {
public:
    bool isValid(string word) {
        if(word.size()<3)return false;
        int voy=0;
        int cons=0;
        for(int i=0;i<word.size();i++){
            char c=word[i];
            c=std::tolower(c);
            if(!(('0'<=c && c<=('0'+9)) || ('a'<=c  && c<='z' ) ))return false;
            
            if( c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')voy++;
            else if (!('0'<=c  && c<=('0'+9)))cons++;
        }
        return (cons>0 && voy>0);

    }
};