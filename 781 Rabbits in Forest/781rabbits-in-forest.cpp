class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int minNum=0;
        bool done[1001];
        int simRabbit[1001];
        for(int i=0;i<answers.size();i++){
            simRabbit[answers[i]]++;
            if(answers[i]==0){
                minNum++;
            }
            else if(simRabbit[answers[i]]==answers[i]+1){
                minNum+=simRabbit[answers[i]];
                simRabbit[answers[i]]=0;
            }
                
            
        }
      /*  for (int i = 0; i < 10; ++i) {
    cout<<simRabbit[i]<<" ";
}
cout<<endl;*/
        for(int i=0;i<1001;i++){
            if(simRabbit[i]<=i && 0<simRabbit[i]){
                minNum+=i+1;
            }
        }
        return minNum;
    }
};