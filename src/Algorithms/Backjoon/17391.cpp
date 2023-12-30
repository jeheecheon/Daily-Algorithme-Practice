#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int diffX[2] = { 0, 1 };
int diffY[2] = { 1, 0 };

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;

    int area[n][m];
    int dist[n][m];
    fill(&dist[0][0], &dist[0][0] + n * m, -1);
    for (int x = 0; x < n; ++x) 
        for (int y = 0; y < m; ++ y) 
            cin >> area[x][y];

    dist[0][0] = 0;
    queue<pair<int, int>> Q;
    Q.push({0, 0});

    while (!Q.empty()) {
        auto cur = Q.front(); Q.pop();

        for (int dir = 0; dir < 2; ++dir) {
            for (int i = 0; i <= area[cur.X][cur.Y]; ++i) {
                int adjX = cur.X + diffX[dir] * i;
                int adjY = cur.Y + diffY[dir] * i;
                
                if (adjX < 0 or adjX >= n or adjY < 0 or adjY >= m)
                    continue;
                if (dist[adjX][adjY] >= 0)
                    continue;

                Q.push({adjX, adjY});
                dist[adjX][adjY] = dist[cur.X][cur.Y] + 1;
            }
        }
    }
    cout << dist[n - 1][m - 1];

    return 0;
}

