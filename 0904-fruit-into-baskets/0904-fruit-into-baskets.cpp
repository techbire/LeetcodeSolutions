class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> ump;
        int maxFruits = 0;
        for (int i = 0, j = 0; j < fruits.size(); j++) {
            ump[fruits[j]]++;
            while (ump.size() > 2) {
                ump[fruits[i]]--;
                if (!ump[fruits[i]]) ump.erase(fruits[i]);
                i++;
            }
            maxFruits = max(maxFruits, j - i);
        }
        return maxFruits;
    }
};