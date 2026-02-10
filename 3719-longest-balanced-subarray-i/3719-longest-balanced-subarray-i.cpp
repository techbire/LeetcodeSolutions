class Solution {
public:
    int longestBalanced(vector<int>& a) {
        int n = a.size(), ans = 0;

        for (int i = 0; i < n; i++) {
            unordered_set<int> even, odd;

            for (int j = i; j < n; j++) {
                if (a[j] & 1) odd.insert(a[j]);
                else even.insert(a[j]);

                if (even.size() == odd.size())
                    ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};
