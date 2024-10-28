class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int maxLen = -1;
        sort(nums.begin(), nums.end());
        int n = nums.size() - 1;
        map<int, int> squares;

        for (int i = 0; i <= n; i++) {
            int num = nums[i];
            long long sq = (long long)num * num;
            if (binary_search(nums.begin(), nums.end(), sq)) {
                squares[num] = sq; // Mapping num to its square
            }
        }

        for (int i = 0; i <= n; i++) {
            int num = nums[i];
            int len = 1;
            while (squares.find(num) != squares.end()) {
                len++;
                num = squares[num];
            }
            maxLen = max(len, maxLen);
        }

        return maxLen < 2 ? -1 : maxLen;
    }
};
