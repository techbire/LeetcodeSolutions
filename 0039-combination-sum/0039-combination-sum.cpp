class Solution {
public:
    vector<vector<int>> a;
    
    void f(int i, int t, vector<int>& c, vector<int>& v) {
        if (t == 0) {
            a.push_back(v);
            return;
        }
        
        if (i == c.size() || t < 0) return;

        v.push_back(c[i]);
        f(i, t - c[i], c, v);   // take (same index again)
        v.pop_back();

        f(i + 1, t, c, v);      // skip
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v;
        f(0, target, candidates, v);
        return a;
    }
};