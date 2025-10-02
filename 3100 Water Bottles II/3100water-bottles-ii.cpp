class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int res = 0;
        int full_bottles = numBottles;
        int Empty_bottles = 0;
        int Bottles_Drunk = 0;
        int num_Ex = numExchange;
        while (!(full_bottles == 0 && Empty_bottles < num_Ex)) {
            if (Empty_bottles < num_Ex) {
                Empty_bottles += full_bottles;
                Bottles_Drunk += full_bottles;
                full_bottles = 0;
            } 
                while (Empty_bottles >= num_Ex) {
                    Empty_bottles -= num_Ex;
                    full_bottles++;
                    num_Ex++;
                }
            
        }
        return Bottles_Drunk;
    }
};