class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i=0,l1=str1.size(),l2=str2.size(),j=0,d=0;
        if(l1<l2){
            return false;
        }
        for(j=0;j<l2 && i<l1;j++){
            // d=((int)(str2[j]-str1[i]));
            // cout<<str1[i]<<" char  "<<d<<endl;
            // cout<<"j "<<j<<endl;
            while((i<l1) &&(!((((int)(str2[j]-str1[i]))==-25)||(0<=((int)(str2[j]-str1[i])) && ((int)(str2[j]-str1[i]))<=1)))){
                // cout<<j<<" l'etat "<<((i<l1) &&(!((d==-25)||(0<=d && d<=1))))<<endl;
                i++;
            }
            
            if(i==l1){
                break;
            }
            i++;
            
        }
        return (i<=l1 && j==l2);
    }
};