class Solution {
    int dfs(int row, int col, vector<vector<int>>& grid) {
        if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size()) return 0;

        if (grid[row][col] == 0) {
            return 0;
        }

        grid[row][col] = 0;

        return 1+
            dfs(row, col-1, grid)+
            dfs(row, col+1, grid)+
            dfs(row-1, col, grid)+
            dfs(row+1, col, grid);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int result = 0;

        for (int r= 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == 1) {
                    result = max(result, dfs(r, c, grid));
                }
            }
        }

        return result;
    }
};
