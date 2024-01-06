#include <bits/stdc++.h>
using namespace std;

pair<int, int> directions[4] = { {1, 0}, {-1, 0}, {0, -1}, {0, 1} };
#define R first
#define C second

bool board[50][50];
int dist[50][50];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int L;
    cin >> L;

    for (int r = 0; r < L; ++r) {
        for (int c = 0; c < L; ++c) {
            char temp;
            cin >> temp;

            dist[r][c] = -1;
            board[r][c] = temp == '1' ? true : false;    
        }
    }

    queue<pair<int, int>> Q;
    Q.push({0, 0});
    dist[0][0] = 0;

    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();

        for (auto nextDir : directions) {
            auto [nextR, nextC] = pair<int, int>(cur.R + nextDir.R, cur.C + nextDir.C);

            if (nextR < 0 || nextR >= L || nextC < 0 || nextC >= L)
                continue;

            if (board[nextR][nextC]) { // 다음 흰방
                if (dist[nextR][nextC] == -1 || dist[nextR][nextC] > dist[cur.R][cur.C]) {
                    Q.push({nextR, nextC});
                    dist[nextR][nextC] = dist[cur.R][cur.C];
                }
            }
            else { // 검은방
                if (dist[nextR][nextC] == -1 || dist[nextR][nextC] > dist[cur.R][cur.C] + 1) {
                    Q.push({nextR, nextC});
                    dist[nextR][nextC] = dist[cur.R][cur.C] + 1;
                }
            }
        }
    }

    cout << dist[L - 1][L - 1]; 
    return 0;
}
