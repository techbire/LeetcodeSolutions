class Solution {
    vector<vector<int>> r;
    vector<int> v;

    void f(vector<int>& a, int t, int i) {
        if (!t) return r.push_back(v);
        
        for (int j = i; j < a.size() && a[j] <= t; j++) {
            if (j > i && a[j] == a[j - 1]) continue;
            v.push_back(a[j]);
            f(a, t - a[j], j + 1);
            v.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& a, int t) {
        sort(a.begin(), a.end());
        f(a, t, 0);
        return r;
    }
};