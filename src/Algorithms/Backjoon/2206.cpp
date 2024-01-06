#include <bits/stdc++.h>
using namespace std;

pair<int, int> directions[4] = { {1, 0}, {-1, 0}, {0, -1}, {0, 1}};
bool board[1000][1000];
int dist[1000][1000][2];

#define R first
#define C second

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int R, C;
    cin >> R >> C;
    
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            char temp;
            cin >> temp;
            if (temp == '1')
                board[r][c] = true;
            dist[r][c][0] = -1;
            dist[r][c][1] = -1;
        }
    }
    
    queue<tuple<int, int, int>> Q;
    Q.push({0, 0, 0});
    dist[0][0][0] = 1;
    dist[0][0][1] = 1;

    while (!Q.empty()) {
        auto cur = Q.front(); Q.pop();

        if (get<0>(cur) == R - 1 && get<1>(cur) == C - 1) {
            cout << dist[get<0>(cur)][get<1>(cur)][get<2>(cur)];
            return 0;
        }

        for (auto nextDir : directions) {
            auto&& [nextR, nextC, nextW] = tuple<int, int, int>(nextDir.R + get<0>(cur), nextDir.C + get<1>(cur), get<2>(cur));

            if (nextR < 0 || nextR >= R || nextC < 0 || nextC >= C)
                continue;
            
            // 다음 이동 벽
            if (board[nextR][nextC]) {
                if (nextW == 1 || dist[nextR][nextC][1] >= 0) { // 이미 벽 하나 뚫었거나 visited
                    continue;
                }

                Q.push({nextR, nextC, 1});
                dist[nextR][nextC][1] = dist[get<0>(cur)][get<1>(cur)][0] + 1;
            }
            else {
                if (dist[nextR][nextC][nextW] >= 0)
                    continue;
                
                Q.push({nextR, nextC, nextW});
                dist[nextR][nextC][nextW] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
            }
        }
    }

    cout << -1;
    return 0;
}
