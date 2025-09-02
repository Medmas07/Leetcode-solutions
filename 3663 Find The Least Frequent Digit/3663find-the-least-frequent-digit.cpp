class Solution {
public:
    int getLeastFrequentDigit(int n) {
        int x = n;
        unsigned int a = -1;
        int freq = 0;
        int res = 9;
        for (int i = 0; i <= 9; i++) {
            x = n;
            freq = 0;

            while (x != 0) {
                int w = x % 10;
                x = x / 10;
                if (w == i) {
                    freq++;
                }
            }
            /* cout<<"freq "<<freq<<endl;
             cout<<"a "<<a<<endl;*/
            if (freq < a && freq != 0) {
                a = freq;
                res = i;
            }
            if (freq == a && i < res) {
                res = i;
            }
        }
        return res;
    }
};