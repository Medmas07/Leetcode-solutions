class Solution {
public:
    int bestClosingTime(string customers) {
        int r=0;
        for(int i=0;i<customers.size();i++){
            if(customers[i]=='Y'){
                r++;
            }
        }
        vector<int> c(customers.size()+1);
        c[0]=r;
        int res=r;
        int w=0;
        for(int i=0;i<c.size()-1;i++){
            if(customers[i]=='Y')
                c[i+1]=c[i]-1;
            else
                c[i+1]=c[i]+1;
            if(c[i]<res){
                res=c[i];
                w=i;
            }
        }
        if(c[c.size()-1]<res){
                res=c[c.size()-1];
                w=c.size()-1;
            }
        return w;

    }
};