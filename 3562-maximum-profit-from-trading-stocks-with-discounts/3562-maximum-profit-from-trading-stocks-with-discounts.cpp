class Solution {
public:
    vector<vector<int>> tree;
    vector<int> pre, fut;
    int B;

    // Returns a vector of 3 DP arrays:
    // res[0] = dp0 -> u does NOT buy
    // res[1] = dp1 -> u buys (Normal Price)
    // res[2] = dp2 -> u buys (Discounted Price)
    vector<vector<int>> dfs(int u) {
        // Initialize the 3 states
        // Use -1e9 to represent invalid states
        vector<int> dp0(B + 1, -1e9);
        vector<int> dp1(B + 1, -1e9);
        vector<int> dp2(B + 1, -1e9);

      
        dp0[0] = 0; // Cost 0, Profit 0

        int cost_norm = pre[u];
        int profit_norm = fut[u] - pre[u];
        if (cost_norm <= B) {
            dp1[cost_norm] = profit_norm;
        }

        int cost_disc = pre[u] / 2;
        int profit_disc = fut[u] - cost_disc;
        if (cost_disc <= B) {
            dp2[cost_disc] = profit_disc;
        }

        for (int v : tree[u]) {
            auto child = dfs(v);
            
            vector<int> ndp0(B + 1, -1e9);
            vector<int> ndp1(B + 1, -1e9);
            vector<int> ndp2(B + 1, -1e9);

        
            // based on whether the parent (u) bought or not.
            vector<int> child_if_parent_no(B + 1);
            vector<int> child_if_parent_yes(B + 1);

            for (int k = 0; k <= B; k++) {
                // If u didn't buy, child can: Not Buy (0) OR Buy Normal (1)
                child_if_parent_no[k] = max(child[0][k], child[1][k]);
                // If u bought, child can: Not Buy (0) OR Buy Discounted (2)
                child_if_parent_yes[k] = max(child[0][k], child[2][k]);
            }

            // Knapsack Merge
            for (int c1 = 0; c1 <= B; c1++) {
                // Optimization: Skip invalid starting states
                if (dp0[c1] == -1e9 && dp1[c1] == -1e9 && dp2[c1] == -1e9) continue;

                for (int c2 = 0; c2 + c1 <= B; c2++) {
                    
                    // Update dp0 (u didn't buy)
                    if (dp0[c1] > -1e9 && child_if_parent_no[c2] > -1e9) {
                        ndp0[c1 + c2] = max(ndp0[c1 + c2], dp0[c1] + child_if_parent_no[c2]);
                    }

                    // Update dp1 (u bought normal) - Uses child_if_parent_yes
                    if (dp1[c1] > -1e9 && child_if_parent_yes[c2] > -1e9) {
                        ndp1[c1 + c2] = max(ndp1[c1 + c2], dp1[c1] + child_if_parent_yes[c2]);
                    }

                    // Update dp2 (u bought discount) - Uses child_if_parent_yes
                 
                    if (dp2[c1] > -1e9 && child_if_parent_yes[c2] > -1e9) {
                        ndp2[c1 + c2] = max(ndp2[c1 + c2], dp2[c1] + child_if_parent_yes[c2]);
                    }
                }
            }

            dp0 = ndp0;
            dp1 = ndp1;
            dp2 = ndp2;
        }

        return {dp0, dp1, dp2};
    }

    int maxProfit(int n, vector<int>& present, vector<int>& future, vector<vector<int>>& hierarchy, int budget) {
        B = budget;
        pre.assign(n + 1, 0);
        fut.assign(n + 1, 0);
        
        // 1-based indexing adjustment
        for (int i = 1; i <= n; i++) {
            pre[i] = present[i - 1];
            fut[i] = future[i - 1];
        }

        tree.assign(n + 1, {});
        vector<int> indeg(n + 1, 0);
        for (auto& e : hierarchy) {
            tree[e[0]].push_back(e[1]);
            indeg[e[1]]++;
        }

        // Find root (CEO)
        int root = 1;
        for (int i = 1; i <= n; i++) {
            if (indeg[i] == 0) {
                root = i;
                break;
            }
        }

        auto ans = dfs(root);

        int res = 0;
        for (int i = 0; i <= B; i++) {
            // CEO cannot be discounted, so we only check ans[0] and ans[1]
            res = max(res, max(ans[0][i], ans[1][i]));
        }

        return res;
    }
};