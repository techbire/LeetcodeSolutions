class Solution {
public:
    vector<int> avoidFlood(vector<int>& rain) {
        int n = rain.size();
        vector<int> ans(n, -1);
        set<int> dry;
        unordered_map<int, int> full;

        for (int i = 0; i < n; ++i) {
            if (rain[i] == 0) {
                dry.insert(i);
                ans[i] = 1;
            } else {
                if (full.count(rain[i])) {
                    auto it = dry.lower_bound(full[rain[i]]);
                    if (it == dry.end()) return {};
                    ans[*it] = rain[i];
                    dry.erase(it);
                }
                full[rain[i]] = i;
            }
        }
        return ans;
    }
};