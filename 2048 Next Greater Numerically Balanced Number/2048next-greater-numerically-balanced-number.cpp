class Solution {
public:
    int isBalanced(int n){
        vector<int> balanced(10,-1);
        int x=n;
        int d=0;
        while(x!=0){
            d=x%10;
            balanced[d]++;
            x=x/10;
        }
        
        int j=0;
        while((j<10)&&(balanced[j]+1 ==j || balanced[j]==-1)){
            j++;
        }

        return j==10;
    }
    int nextBeautifulNumber(int n) {
        int i=n+1;
        while( !isBalanced(i)){
            i++;
        }   
        return i;
    }
};