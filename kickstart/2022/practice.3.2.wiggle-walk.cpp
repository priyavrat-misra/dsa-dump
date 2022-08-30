#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        int n, r, c, x, y;
        cin >> n >> r >> c >> x >> y;
        string cmd;
        cin >> cmd;
        
        vector<vector<bool>> grid(r);
        for (int j = 0; j < r; ++j) {
            vector<bool> row(c);
            grid[j] = row;
        }
        
        --x;
        --y;
        grid[x][y] = true;
        for (char& dir : cmd) {
            if (dir == 'N') {
                while (x > 0 && grid[x][y])
                    --x;
            } else if (dir == 'S') {
                while (x < r - 1 && grid[x][y])
                    ++x;
            } else if (dir == 'W') {
                while (y > 0 && grid[x][y])
                    --y;
            } else if (dir == 'E') {
                while (y < c - 1 && grid[x][y])
                    ++y;
            }
            
            grid[x][y] = true;
        }
        
        cout << "Case #" << i << ": "
            << x + 1 << " " << y + 1 << endl;
    }
}
