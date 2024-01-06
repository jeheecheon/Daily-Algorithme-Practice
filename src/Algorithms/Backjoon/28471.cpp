#include <bits/stdc++.h>
using namespace std;

pair<int, int> directions[7] = { {1, -1}, {1, 1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1} };
bool board[2000][2000];
bool visited[2000][2000];

#define R first
#define C second

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int L;
    cin >> L;
    
    char c;
    pair<int, int> F;
    for (int r = 0; r < L; ++r) {
        for (int c = 0; c < L; ++c) {
            char temp;
            cin >> temp;
            if (temp == '#')
                board[r][c] = true;
            else if (temp == 'F')
                F = {r, c};
        }
    }

    int cnt = 0;
    
    queue<pair<int, int>> Q;
    visited[F.R][F.C] = true;
    Q.push({F.R, F.C});

    while (!Q.empty()) {
        auto cur = Q.front(); Q.pop();

        for (auto nextDir : directions) {
            auto [nextR, nextC] = pair<int, int>(cur.R + nextDir.R, cur.C + nextDir.C);

            if (nextR < 0 || nextR >= L || nextC < 0 || nextC >= L
                || visited[nextR][nextC] // 이미 방문했는 곳
                || board[nextR][nextC]) // 벽일 때
                continue;
            
            if (board[nextR][nextC] == false)
                ++cnt;
            visited[nextR][nextC] = true;
            Q.push({nextR, nextC});
        }
    }

    cout << cnt;

    return 0;
}
