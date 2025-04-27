class Solution {
public:
    int arrangeCoins(int n) {
        long right=n;
        long left=0;
        while(left<=right){
            long mid=left+(right-left)/2;
            long curr=mid*(mid+1)/2;
            if(n==curr)return mid;
            else if (curr<n){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return right;
    }
};