class Solution {
public:
    int sumdigit(int i){
        string s=to_string(i);
        int sum=0;
        for(int j=0;j<s.length();j++){
            sum+=(s[j]-'0');
        }
        return sum;
    }
    int countLargestGroup(int n) {
        map<int,int> nb_groups;
        if(n==1){
            return 1;
        }
        for(int i=1; i<=n ; i++){
           // cout<<sumdigit(i)<<endl;
            nb_groups[sumdigit(i)]++;
        }
        int i_max=0;
        int res=0;
        //cout<<"________________________"<<endl;
        for(int k=1;k<nb_groups.size();k++){
            //cout<<nb_groups[k]<<endl;
            if(nb_groups[i_max]<nb_groups[k]){
                i_max=k;
                res=0;
            }
            if(nb_groups[i_max]==nb_groups[k]){
                res++;
            }
           // cout<<"result"<<res<<endl;
        }
        return res;
    }
};