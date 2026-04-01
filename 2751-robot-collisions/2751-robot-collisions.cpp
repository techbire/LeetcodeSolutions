class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& p, vector<int>& h, string d) {
        int n = p.size();

        // {index, position, health, direction}
        vector<vector<int>> a;
        for (int i = 0; i < n; i++) {
            a.push_back({i, p[i], h[i], d[i] == 'R'});
        }

        // sort by position
        sort(a.begin(), a.end(), [](auto &x, auto &y) {
            return x[1] < y[1];
        });

        vector<vector<int>> st; // stack

        for (auto &x : a) {
            if (x[3] == 1) {
                // right moving → push
                st.push_back(x);
            } else {
                // left moving → collision
                while (!st.empty() && st.back()[3] == 1 && x[2] > 0) {
                    if (st.back()[2] > x[2]) {
                        st.back()[2]--;
                        x[2] = 0;
                    } else if (st.back()[2] < x[2]) {
                        x[2]--;
                        st.pop_back();
                    } else {
                        st.pop_back();
                        x[2] = 0;
                    }
                }
                if (x[2] > 0) st.push_back(x);
            }
        }

        // sort back by original index
        sort(st.begin(), st.end(), [](auto &x, auto &y) {
            return x[0] < y[0];
        });

        vector<int> ans;
        for (auto &x : st) ans.push_back(x[2]);

        return ans;
    }
};