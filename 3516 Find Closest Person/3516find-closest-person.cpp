class Solution {
public:
    int findClosest(int x, int y, int z) {
        int d_abs=(x<z)?z-x:x-z;
        int d1_abs=(y<z)?z-y:y-z;

        return (d_abs<d1_abs)?1:((d_abs==d1_abs)?0:2);
    }
};