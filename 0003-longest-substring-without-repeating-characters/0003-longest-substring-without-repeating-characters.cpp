class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxilen = 0;
        int left = 0;
        unordered_set<char> set;
        for (int right = 0; right < n; right++) {
            while (set.count(s[right])) {
                set.erase(s[left]);
                left++;
            }

            set.insert(s[right]);
            maxilen = max(maxilen, right - left + 1);
        }

        return maxilen;
    }
};