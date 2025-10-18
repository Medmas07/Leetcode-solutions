class Solution {
public:
    int calPoints(vector<string>& operations) {
        int res=0;
        vector<int> a;
        for(int i=0;i<operations.size();i++){
            if(operations[i]!="+" && operations[i]!="D" && operations[i]!="C"){
               a.push_back(stoi(operations[i]));

            }else if(operations[i]=="+"){
                a.push_back(a[a.size()-1]+a[a.size()-2]);

            }else if(operations[i]=="D"){
                a.push_back(a[a.size()-1]*2);
                
            }else{
                a.erase(a.begin()+a.size()-1);
            }
        }
        for(int j=0;j<a.size();j++){
            res+=a[j];
        }
        return res;
    }
};