#include <bits/stdc++.h>
using namespace std;

pair<int, int> directions[4] = { {1, 0}, {-1, 0}, {0, -1}, {0, 1}};
#define R first
#define C second

bool board[1000][1000];
bool visited[1000][1000];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int R, C;
    cin >> R >> C;

    for (int r = 0; r < R; ++r) 
        for (int c = 0; c < C; ++c) 
            cin >> board[r][c];

    int cnt = 0;
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            if (!board[r][c] && !visited[r][c]) {
                ++cnt;

                queue<pair<int, int>> Q;
                visited[r][c] = true;
                Q.push({r, c});

                while (!Q.empty()) {
                    auto cur = Q.front(); Q.pop();

                    for (auto nextDir : directions) {
                        auto [nextR, nextC] = pair<int, int>(cur.R + nextDir.R, cur.C + nextDir.C);

                        if (nextR >= R)
                            nextR %= R;
                        else if (nextR < 0)
                            nextR = R + nextR;
                        else if (nextC >= C)
                            nextC %= C;
                        else if (nextC < 0)
                            nextC = C + nextC;
                        
                        if (visited[nextR][nextC] || board[nextR][nextC])
                            continue;
                        
                        visited[nextR][nextC] = true;
                        Q.push({nextR, nextC});
                    }
                }
            }
        }
    }

    cout << cnt;
    return 0;
}
