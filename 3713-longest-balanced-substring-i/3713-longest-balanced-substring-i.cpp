class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size(), ans = 0;

        for (int i = 0; i < n; i++) {
            vector<int> f(26, 0);
            int d = 0, mx = 0;

            for (int j = i; j < n; j++) {
                if (f[s[j] - 'a']++ == 0) d++;   // new character
                mx = max(mx, f[s[j] - 'a']);     // max frequency

                if ((j - i + 1) == d * mx)
                    ans = max(ans, j - i + 1);
            }
        }

        return ans;
    }
};
