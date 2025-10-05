class Solution {
public:
    
    string removeSubstring(string s, int k) {
        string t;
        int n=s.size();
        for(char c :s){
            t.push_back(c);
            if(t.size()>=2*k){
                bool ok=true ;
                for(int i=t.size()-2*k;i<t.size()-k;i++){
                    if(t[i]!='('){ok=false;break;}
                }

                for(int i=t.size()-k;i<t.size();i++){
                    if(t[i]!=')'){ok=false;break;}
                }
                if(ok){
                    t.erase(t.end()-2*k, t.end());
                }
            }
        }
        return t;
    }
};