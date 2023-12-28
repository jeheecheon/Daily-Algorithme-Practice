#include <bits/stdc++.h>
using namespace std;

int diffX[6] = { 0, 1, 0, -1, 0, 0 };
int diffY[6] = { 1, 0, -1, 0, 0, 0};
int diffZ[6] = { 0, 0, 0, 0, -1, 1};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, h;
    cin >> m >> n >> h;
    int board[n][m][h];
    int dist[n][m][h];
    fill(&dist[0][0][0], &dist[0][0][0] + n * m * 2, 0);

    queue<tuple<int, int, int>> Q;
    for (int z = 0; z < h; ++z)
        for (int x = 0; x < n; ++x)
            for (int y = 0; y < m; ++y) {
                cin >> board[x][y][z];
                if (board[x][y][z] == 1) 
                    Q.push({x, y, z});
                else if (board[x][y][z] == 0)
                    dist[x][y][z] = -1;
            } 

    while(!Q.empty()) {
        tuple<int, int, int> curPos = Q.front(); 
        Q.pop();

        for (int iter = 0; iter < 6; ++iter) {
            int adjX = get<0>(curPos) + diffX[iter];
            int adjY = get<1>(curPos) + diffY[iter];
            int adjZ = get<2>(curPos) + diffZ[iter];

            // Check if the adjacent pos is in the size of board
            if (adjX < 0 or adjX >= n or adjY < 0 or adjY >= m or adjZ < 0 or adjZ >= h)
                continue;
            
            // Check if the adjacent pos is alrady visited and a valid path
            if (dist[adjX][adjY][adjZ] >= 0)
                continue;

            Q.push({adjX, adjY, adjZ});
            dist[adjX][adjY][adjZ] = dist[get<0>(curPos)][get<1>(curPos)][get<2>(curPos)] + 1;
        }
    }

    int maxDaysNeeded = 0;
    for (int z = 0; z < h; ++z)
        for (int x = 0; x < n; ++x)
            for (int y = 0; y < m; ++y) {
                if (dist[x][y][z] == -1) {
                    cout << -1;
                    return 0;
                }
                maxDaysNeeded = max(maxDaysNeeded, dist[x][y][z]);
            } 

    cout << maxDaysNeeded;
    return 0;
}