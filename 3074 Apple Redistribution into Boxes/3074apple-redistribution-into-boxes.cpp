class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
       sort(capacity.begin(),capacity.end(),greater<int>());
       int sum=0;
       for(int i=0;i<apple.size();i++){
        sum+=apple[i];
       } 
       int sum1=0;
       int i=0;
       while(i<capacity.size() && sum1<sum){
        sum1+=capacity[i];
        i++;
       }
       return i;
    }
};