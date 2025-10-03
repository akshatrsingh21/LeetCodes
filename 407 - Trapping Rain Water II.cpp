class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        if (m == 0) return 0;
        int n = heightMap[0].size();
        if (n == 0) return 0;

        using Cell = tuple<int, int, int>; // {height, i, j}
        priority_queue<Cell, vector<Cell>, greater<Cell>> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // Add boundary cells
        for (int i = 0; i < m; i++) {
            pq.push({heightMap[i][0], i, 0});
            pq.push({heightMap[i][n - 1], i, n - 1});
            visited[i][0] = visited[i][n - 1] = true;
        }
        for (int j = 0; j < n; j++) {
            pq.push({heightMap[0][j], 0, j});
            pq.push({heightMap[m - 1][j], m - 1, j});
            visited[0][j] = visited[m - 1][j] = true;
        }

        int water = 0;
        vector<pair<int, int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};

        // Process cells from the priority queue
        while (!pq.empty()) {
            auto [h, i, j] = pq.top();
            pq.pop();

            for (auto& [dx, dy] : dirs) {
                int x = i + dx, y = j + dy;
                if (x >= 0 && x < m && y >= 0 && y < n && !visited[x][y]) {
                    water += max(0, h - heightMap[x][y]);
                    pq.push({max(h, heightMap[x][y]), x, y});
                    visited[x][y] = true;
                }
            }
        }

        return water;
    }
};
