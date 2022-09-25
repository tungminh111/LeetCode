#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ret = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) if (grid[i][j] == '1') {
                dfs(grid, i, j);
                ret += 1;
            }
        }
        return ret;
    }

    void dfs(vector<vector<char>>& grid, const int& i, const int& j) {
        if (i >= grid.size() || i < 0 || j >= grid[0].size() || j < 0)
            return;
        if (grid[i][j] == '0') return;
        grid[i][j] = '0';
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }

};

int main() {
    ifstream input;
    input.open("input.txt");

    ofstream output;
    output.open("output.txt");

    vector<vector<char>> grid;
    char c;
    int i = 0;
    int j = 0;
    vector<char> tmp;
    while (input.get(c)) {
        if (c == '\n') {
            i++;
            j = 0;
            grid.emplace_back(tmp);
            tmp.clear();
            continue;
        }
        tmp.emplace_back(c);
    }

    int ret = Solution().numIslands(grid);
    output << ret << endl;

    input.close();
    output.close();
    return 0;
}
