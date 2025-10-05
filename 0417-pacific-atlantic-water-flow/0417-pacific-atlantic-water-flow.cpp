class Solution {
public:
    int m, n;
    vector<vector<int>> dir{{1,0},{-1,0},{0,1},{0,-1}};

    void dfs(vector<vector<int>>& h, vector<vector<int>>& vis, int r, int c) {
        vis[r][c] = 1;
        for (auto &d : dir) {
            int nr = r + d[0], nc = c + d[1];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && !vis[nr][nc] && h[nr][nc] >= h[r][c])
                dfs(h, vis, nr, nc);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        m = h.size(), n = h[0].size();
        vector<vector<int>> pac(m, vector<int>(n)), atl(m, vector<int>(n));
        for (int i = 0; i < m; ++i) dfs(h, pac, i, 0), dfs(h, atl, i, n-1);
        for (int j = 0; j < n; ++j) dfs(h, pac, 0, j), dfs(h, atl, m-1, j);
        vector<vector<int>> res;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (pac[i][j] && atl[i][j]) res.push_back({i, j});
        return res;
    }
};