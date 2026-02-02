class Solution {
    int min_unfair = INT_MAX;

public:
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> child(k, 0);
        rec(0, child, cookies, k);
        return min_unfair;
    }

    void rec(int i, vector<int>& child, vector<int>& cookies, int k) {
        if (i == cookies.size()) {
            int max_cookie = 0;
            for (int x : child)
                max_cookie = max(max_cookie, x);
            min_unfair = min(min_unfair, max_cookie);
            return;
        }

        for (int j = 0; j < k; j++) {
            child[j] += cookies[i];
            rec(i + 1, child, cookies, k);
            child[j] -= cookies[i];
        }
    }
};
