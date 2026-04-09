#include <bits/stdc++.h>
using namespace std;

bool canCatch(vector<vector<int>> grid) {
    int row = grid.size();
    int col = grid[0].size();
    int mx, my, c1x, c1y, c2x, c2y;
    cin >> mx >> my >> c1x >> c1y >> c2x >> c2y;

    vector<pair<int, int>> directions;
    directions.push_back(make_pair(1, 0));
    directions.push_back(make_pair(-1, 0));
    directions.push_back(make_pair(0, 1));
    directions.push_back(make_pair(0, -1));

    queue<pair<int, int>> m;
    queue<pair<int, int>> c;
    m.push(make_pair(mx-1, my-1));
    if (mx-1 < 0 || mx-1 >= row || my-1 < 0 || my-1 >= col) return true;
    //multi source bfs
    c.push(make_pair(c1x-1, c1y-1));
    c.push(make_pair(c2x-1, c2y-1));
  

    vector<vector<int>> visited_c(row, vector<int>(col, INT_MAX));
    vector<vector<int>> visited_m(row, vector<int>(col, -1));
   
    int steps=0;
    visited_c[c1x-1][c1y-1] = 0;
    visited_c[c2x-1][c2y-1] = 0;
    visited_m[mx-1][my-1]=0;

    while (!c.empty()) {
        // all cat best minimum move to reach all the cells movement
        int size = c.size();
        for (int i = 0; i < size; i++) {
            int k = c.front().first;
            int l = c.front().second;
            c.pop();
            for (size_t d = 0; d < directions.size(); d++) {
                int tx = directions[d].first;
                int ty = directions[d].second;
                int ni = k + tx;
                int ny = l + ty;
                if (ni >= 0 && ni < row && ny >= 0 && ny < col) {
                        if (visited_c[ni][ny] > steps+1) {
                            c.push(make_pair(ni, ny));
                            visited_c[ni][ny] = steps+1;
                        }
                }
            }
        }
        steps++;
    }
    steps=0;
    //the mouse movements
    while(!m.empty()){
        int size = m.size();
        for (int i = 0; i < size; i++) {
            int k = m.front().first;
            int l = m.front().second;
            m.pop();
            for (size_t d = 0; d < directions.size(); d++) {
                int tx = directions[d].first;
                int ty = directions[d].second;
                int ni = k + tx;
                int ny = l + ty;
                if (ni >= 0 && ni < row && ny >= 0 && ny < col) {
                        if (visited_c[ni][ny] >= steps+1 && visited_m[ni][ny] == -1) {
                            m.push(make_pair(ni, ny));
                            visited_m[ni][ny]=steps+1;
                        }
                }else if(visited_c[k][l] > steps ) {
                    return true;
                }
            }
        }
        steps++;


    }

    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid;
    int t;
    cin >> t;
    while (t--) {
        grid.clear();
        grid.resize(n, vector<int>(m));
          if (canCatch(grid)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
