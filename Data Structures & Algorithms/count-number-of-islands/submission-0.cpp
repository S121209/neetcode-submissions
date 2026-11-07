class Solution {
    void dfs(int row, int col, vector<vector<char>>& grid) {
        if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size()) {
            return;
        }

        if (grid[row][col] == '0') {
            return;
        }
        grid[row][col] = '0';

        dfs(row-1, col, grid);
        dfs(row+1, col, grid);
        dfs(row, col-1, grid);
        dfs(row, col+1, grid);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int islandCount = 0;

        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == '1') {
                    islandCount++;
                    dfs(r, c, grid);
                }
            }
        }

        return islandCount;
    }
};
