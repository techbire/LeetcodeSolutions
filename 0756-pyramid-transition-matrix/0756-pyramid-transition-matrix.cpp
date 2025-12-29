class Solution {
    map<pair<char,char>, vector<char>> mp;
    unordered_map<string,bool> dp;

    bool dfs(string cur) {
        if (cur.size() == 1) return true;
        if (dp.count(cur)) return dp[cur];

        function<bool(int,string&)> build = [&](int i, string &next) {
            if (i == cur.size() - 1)
                return dfs(next);

            auto key = make_pair(cur[i], cur[i+1]);
            if (!mp.count(key)) return false;

            for (char c : mp[key]) {
                next.push_back(c);
                if (build(i + 1, next)) return true;
                next.pop_back();
            }
            return false;
        };

        string next = "";
        return dp[cur] = build(0, next);
    }

public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for (auto &s : allowed)
            mp[{s[0], s[1]}].push_back(s[2]);

        return dfs(bottom);
    }
};
