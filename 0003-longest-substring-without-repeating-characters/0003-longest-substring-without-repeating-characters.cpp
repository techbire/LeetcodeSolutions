class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> last;
        int left = 0;
        int best = 0;

        for (int right = 0; right < s.length(); right++) {
            char ch = s[right];

            if (last.find(ch) != last.end() && last[ch] >= left) {
                left = last[ch] + 1;
            }

            last[ch] = right;

            int curr = right - left + 1;
            best = max(best, curr);
        }

        return best;
    }
};