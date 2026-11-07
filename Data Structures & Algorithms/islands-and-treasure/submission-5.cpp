class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == 0) {
                    q.push({r, c});
                    visited[r][c] = true;
                }
            }
        }

        int count = 0;

        while(!q.empty()) {
            int qSize = q.size();

            for (int i = 0; i < qSize; i++) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                grid[r][c] = count;
                
                int dr[4] = {0, 0, -1, 1};
                int dc[4] = {-1, 1, 0, 0};

                for (int j = 0; j < 4; j++) {
                    int nr = r+dr[j];
                    int nc = c+dc[j];

                    if (nr < 0 || nc < 0 || nr >= grid.size() || nc >= grid[0].size() || visited[nr][nc] == true || grid[nr][nc] == -1 || grid[nr][nc] == 0) {
                        continue;
                    }

                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
            count++;
        }
    }
};
