class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int res=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            
                    int a=nums[i];
                    int b=nums[i+1];
                    int c=nums[i+2];

                    //double s=(double)(0.5*(a+b+c));
                    //double t=sqrt(s*(s-a)*(s-b)*(s-c));
                    //cout<<"s= "<<s<<endl;
                    //cout<<t<<endl;
                    if(a+b>c && a+c>b && b+c>a){
                        if((a+b+c)>res){
                        res=a+b+c;
                    }
                    } 
        }
        return res;
    }
};