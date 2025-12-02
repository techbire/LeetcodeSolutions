class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        const int MOD = 1000000007;
        unordered_map<int, int> freq; // stores count of each y-coordinate

        // count frequency of each y
        for (auto &p : points) {
            freq[p[1]]++;
        }

        long long ans = 0;
        long long totalPairs = 0;

        // calculate number of pairs having same y
        for (auto &entry : freq) {
            int count = entry.second;
            // pair
            if (count < 2) continue;
            // nC2
            long long pairs = (1LL * count * (count - 1) / 2) % MOD;
            // Add trapezoids 
            ans = (ans + totalPairs * pairs) % MOD;
            totalPairs = (totalPairs + pairs) % MOD;
        }

        return ans;
    }
};
