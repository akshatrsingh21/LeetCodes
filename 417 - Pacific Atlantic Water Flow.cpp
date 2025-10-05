class Solution {
public:
    int m, n;
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty() || heights[0].empty()) return {};

        m = heights.size();
        n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        // DFS from Pacific (top row, left column)
        for (int i = 0; i < m; i++)
            dfs(heights, pacific, i, 0);
        for (int j = 0; j < n; j++)
            dfs(heights, pacific, 0, j);

        // DFS from Atlantic (bottom row, right column)
        for (int i = 0; i < m; i++)
            dfs(heights, atlantic, i, n - 1);
        for (int j = 0; j < n; j++)
            dfs(heights, atlantic, m - 1, j);

        // Collect cells that can reach both oceans
        vector<vector<int>> result;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j])
                    result.push_back({i, j});
            }
        }

        return result;
    }

private:
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& ocean, int i, int j) {
        ocean[i][j] = true;

        for (auto& d : dirs) {
            int ni = i + d[0], nj = j + d[1];
            if (ni >= 0 && ni < m && nj >= 0 && nj < n &&
                !ocean[ni][nj] &&
                heights[ni][nj] >= heights[i][j]) {
                dfs(heights, ocean, ni, nj);
            }
        }
    }
};
