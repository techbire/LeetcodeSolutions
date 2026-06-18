class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> r;
        vector<int> p;
        dfs(nums, p, r);
        return r;
    }

    void dfs(vector<int> n, vector<int> p, vector<vector<int>>& r) {
        if (n.empty()) {
            r.push_back(p);
            return;
        }

        for (int i = 0; i < n.size(); i++) {
            vector<int> t = n;
            vector<int> q = p;

            q.push_back(t[i]);
            t.erase(t.begin() + i);

            dfs(t, q, r);
        }
    }
};