class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int res=0;
        bool notBroken=true;
        for(int i=0;i<text.size();i++){
            
            for(int j=0;j<brokenLetters.size();j++)
            {
                if(text[i]==brokenLetters[j]){
                    notBroken=false;
                    break;
                }
            }
            //cout<<" i = "<<i<<endl; 
            //cout<<"test  "<<notBroken<<endl;
            if(text[i]==' '){
               if(notBroken)res++;
                notBroken=true;
            }
        }
        if(notBroken){
            res++;
        }


        return res;
    }
};