class Solution {
public:
//     vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
//         int size=size.of(spells)*size.of(potions);
//         for(int i=0;i<size;i++){
//         spells[i]*potion[j];

// if(spells[i])
// {
//     check is it factor of success or not
//     if yes pair up and return number
//  of pair
//  in a array}

//     }
// };

     vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int n = potions.size();
        vector<int> ans;

        for (int spell : spells) {
            long long need = (success + spell - 1) / spell; // smallest potion needed
            auto it = lower_bound(potions.begin(), potions.end(), need);
            ans.push_back(potions.end() - it); // number of potions that succeed
        }
        return ans;
    }
};