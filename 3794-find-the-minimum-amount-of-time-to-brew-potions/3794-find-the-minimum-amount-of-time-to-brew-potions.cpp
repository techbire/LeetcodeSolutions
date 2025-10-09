class Solution {
public:
    using ll = long long;
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size(), m = mana.size();
        vector<ll> f(n, 0);
        for (int i = 0; i < m; i++) {
            ll now = f[0], x = mana[i];
            for (int j = 1; j < n; j++) {
                now = max(now + skill[j - 1] * x, f[j]);
            }
            f[n - 1] = now + skill[n - 1] * x;
            for (int i = n - 2; i >= 0; i--)
                f[i] = f[i + 1] - skill[i + 1] * x;
        }
        return f[n - 1];
    }
};