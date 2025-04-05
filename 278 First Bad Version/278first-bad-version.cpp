// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int m=n;
        /*for(int i=1;i<=n;i++){
            if(isBadVersion(i)){
                return i;
            }
        }*/
        int left=1;
        int right=n;
        
        while(left<right){
            m=(left)+(right-left)/2;
            if(isBadVersion(m)){
                right=m;
            }
            if(!(isBadVersion(m))){
                left=m+1;
            }
            cout<<m<<endl;
        }
        return left;
    }
};