class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int drunk = 0, empty = 0;
        while (numBottles > 0) {
            drunk += numBottles;
            empty += numBottles;
            numBottles = 0;
            if (empty >= numExchange) {
                empty -= numExchange;
                numBottles = 1;
                ++numExchange;
            }
        }
        return drunk;
    }
};