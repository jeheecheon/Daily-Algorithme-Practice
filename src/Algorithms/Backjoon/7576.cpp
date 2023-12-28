#include <bits/stdc++.h>
using namespace std;

int diffX[4] = { 0, 1, 0, -1 };
int diffY[4] = { 1, 0, -1, 0, };

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> m >> n;
    int board[n][m];
    int dist[n][m];
    fill(&dist[0][0], &dist[0][0] + n * m, 0);
    queue<pair<int, int>> Q;
    for (int x = 0; x < n; ++x)
        for (int y = 0; y < m; ++y) {
            cin >> board[x][y];
            if (board[x][y] == 1) 
                Q.push({x, y});
            else if (board[x][y] == 0)
                dist[x][y] = -1;
        } 

    while(!Q.empty()) {
        pair<int, int> curPos = Q.front(); 
        Q.pop();

        for (int iter = 0; iter < 4; ++iter) {
            int adjX = curPos.first + diffX[iter];
            int adjY = curPos.second + diffY[iter];

            // Check if the adjacent pos is in the size of board
            if (adjX < 0 or adjX >= n or adjY < 0 or adjY >= m)
                continue;
            
            // Check if the adjacent pos is alrady visited and a valid path
            if (dist[adjX][adjY] >= 0)
                continue;

            Q.push({adjX, adjY});
            dist[adjX][adjY] = dist[curPos.first][curPos.second] + 1;
        }
    }

    int maxDaysNeeded = 0;
    for (int x = 0; x < n; ++x)
        for (int y = 0; y < m; ++y) {
            if (dist[x][y] == -1) {
                cout << -1;
                return 0;
            }
            maxDaysNeeded = max(maxDaysNeeded, dist[x][y]);
        } 

    cout << maxDaysNeeded;
    return 0;
}