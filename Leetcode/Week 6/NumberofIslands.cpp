class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), count = 0;

        auto markIsland = [&](int i, int j){
            queue<pair<int,int>> q;
            q.push({i,j});
            grid[i][j] = '0';
            while(!q.empty()){
                auto temp = q.front();
                q.pop();
                int a = temp.first, b = temp.second;
                // right
                if (b + 1 < n && grid[a][b + 1] == '1') {
                    grid[a][b + 1] = '0';
                    q.push({a, b + 1});
                }
                // left
                if (b - 1 >= 0 && grid[a][b - 1] == '1') {
                    grid[a][b - 1] = '0';
                    q.push({a, b - 1});
                }
                // down
                if (a + 1 < m && grid[a + 1][b] == '1') {
                    grid[a + 1][b] = '0';
                    q.push({a + 1, b});
                }
                // up
                if (a - 1 >= 0 && grid[a - 1][b] == '1') {
                    grid[a - 1][b] = '0';
                    q.push({a - 1, b});
                }
            }
        };

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    markIsland(i, j);
                    count++;
                }
            }
        }
        return count;
    }
};
