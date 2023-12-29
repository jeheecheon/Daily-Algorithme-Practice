#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int diffX[4] = { 0, 1, 0, -1};
int diffY[4] = { 1, 0, -1, 0};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    char board[n][m];
    int fireDist[n][m];
    int JDist[n][m];
    fill(&fireDist[0][0], &fireDist[0][0] + n * m, -1);
    fill(&JDist[0][0], &JDist[0][0] + n * m, -1);

    queue<pair<int, int>> JQ, FQ;
    for (int x = 0; x < n; ++x)
        for (int y = 0; y < m; ++y) {
            cin >> board[x][y];
            if (board[x][y] == 'J') {
                JQ.push({x, y});
                JDist[x][y] = 0;
            }
            else if (board[x][y] == 'F') {
                FQ.push({x, y});
                fireDist[x][y] = 0;
            }
        } 

    // Fire BFS
    while(!FQ.empty()) {
        pair<int, int> curPos = FQ.front(); 
        FQ.pop();

        for (int iter = 0; iter < 4; ++iter) {
            int adjX = curPos.X + diffX[iter];
            int adjY = curPos.Y + diffY[iter];

            // Check if the adjacent pos is in the size of board
            if (adjX < 0 or adjX >= n or adjY < 0 or adjY >= m)
                continue;
            
            // Check if the adjacent pos is alrady visited and a valid path
            if (fireDist[adjX][adjY] >= 0 or board[adjX][adjY] == '#')
                continue;

            FQ.push({adjX, adjY});
            fireDist[adjX][adjY] = fireDist[curPos.X][curPos.Y] + 1;
        }
    }

    // Jihoon BFS
    while(!JQ.empty()) {
        pair<int, int> curPos = JQ.front(); 
        JQ.pop();

        for (int iter = 0; iter < 4; ++iter) {
            int adjX = curPos.X + diffX[iter];
            int adjY = curPos.Y + diffY[iter];

            // Check if Jihoon can escape
            if (adjX < 0 or adjX >= n or adjY < 0 or adjY >= m) {
                cout << JDist[curPos.X][curPos.Y] + 1;
                return 0;
            }
            
            // Check if the path chosen is blocked or on fire by the time Jihoon gets there
            if (JDist[adjX][adjY] >= 0 or board[adjX][adjY] == '#' 
                or (fireDist[adjX][adjY] != -1 and JDist[curPos.X][curPos.Y] + 1 >= fireDist[adjX][adjY]))
                continue;

            JQ.push({adjX, adjY});
            JDist[adjX][adjY] = JDist[curPos.X][curPos.Y] + 1;
        }
    }

    cout << "IMPOSSIBLE";

    return 0;
}