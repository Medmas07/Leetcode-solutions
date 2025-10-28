class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = 0;
        int w = nums.size();
        
        for (int i = 0; i < w; i++) {
            if (nums[i] == 0) {
                // ====== Première direction ======
                vector<int> tmpv = nums;
                int direction = 1;
                int curr = i + direction;

                while (0 <= curr && curr < tmpv.size()) {
                    if (tmpv[curr] == 0) {
                        curr += direction;
                    } else if (tmpv[curr] > 0) {
                        tmpv[curr]--;
                        direction = -direction;
                        curr += direction;
                    }
                }

                bool allZero = true;
                for (int val : tmpv) {
                    if (val != 0) {
                        allZero = false;
                        break;
                    }
                }

                if (allZero) n++;

                // ====== Deuxième direction ======
                tmpv = nums;
                direction = -1;
                curr = i + direction;

                while (0 <= curr && curr < tmpv.size()) {
                    if (tmpv[curr] == 0) {
                        curr += direction;
                    } else if (tmpv[curr] > 0) {
                        tmpv[curr]--;
                        direction = -direction;
                        curr += direction;
                    }
                }

                allZero = true;
                for (int val : tmpv) {
                    if (val != 0) {
                        allZero = false;
                        break;
                    }
                }

                if (allZero) n++;
            }
        }

        return n;
    }
};
