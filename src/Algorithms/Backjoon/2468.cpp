#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int diffX[4] = { 0, -1, 0, 1};
int diffY[4] = { 1, 0, -1, 0};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    int area[N][N];
    
    int lowest = INT_MAX, heighest = 0;
    for (int x = 0; x < N; ++x)
        for (int y = 0; y < N; ++y) {
            cin >> area[x][y];
            lowest = min(lowest, area[x][y]);
            heighest = max(heighest, area[x][y]);
        }

    queue<int> Q;
    int maxCnt = 0;

    for (int j = lowest - 1; j <= heighest; ++j) {
        bool visited[N][N];
        fill(&visited[0][0], &visited[0][0] + N * N, false);
        int cnt = 0;

        for (int x = 0; x < N; ++x) {
            for (int y = 0; y < N; ++y) {
                if (!visited[x][y] and area[x][y] > j) {
                    ++cnt;

                    // start bfsx
                    queue<pair<int, int>> Q;
                    Q.push({x, y});
                    visited[x][y] = true;

                    while(!Q.empty()) {
                        auto cur = Q.front();
                        Q.pop();

                        for (int i = 0; i < 4; ++i) {
                            int adjX = cur.X + diffX[i];
                            int adjY = cur.Y + diffY[i];

                            if (adjX < 0 or adjX >= N or adjY < 0 or adjY >= N)
                                continue;
                            if (visited[adjX][adjY] or area[adjX][adjY] <= j)
                                continue;
                            
                            Q.push({adjX, adjY});
                            visited[adjX][adjY] = true;
                        }
                    }
                }
            }
        }
        maxCnt = max(cnt, maxCnt);
    }

    cout << maxCnt;    

    return 0;
}