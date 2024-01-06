#include <bits/stdc++.h>
using namespace std;
// 아빠는 청국장, 엄마는 스시, 아이는 맥앤치즈가 먹고 

pair<int, int> directions[4] = { {1, 0}, {-1, 0}, {0, -1}, {0, 1}};
char board[3000][3000];
int dist[3000][3000];

#define R first
#define C second

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    
    queue<pair<int, int>> Q;

    for (int n = 0; n < N; ++n) {
        for (int m = 0; m < M; ++m) {
            cin >> board[n][m];
            if (board[n][m] == '2') {
                Q.push({n, m});
                dist[n][m] = 0;
            }
            else
                dist[n][m] = -1;
        }
    }

    bool reached = false;
    int cnt = 0;
    while (!reached && !Q.empty()) {
        auto cur = Q.front(); Q.pop();

        for (auto nextDir : directions) {
            auto&& [nextR, nextC] = pair<int, int>(nextDir.R + cur.R, nextDir.C + cur.C);

            if (nextR < 0 || nextR >= N || nextC < 0 || nextC >= M
                || dist[nextR][nextC] >= 0
                || board[nextR][nextC] == '1')
                continue;
            
            if (board[nextR][nextC] == '0') {
                Q.push({nextR, nextC});
                dist[nextR][nextC] = dist[cur.R][cur.C] + 1;
            }
            // 음식
            else {
                reached = true;
                cnt = dist[cur.R][cur.C] + 1;
                break;
            }
        }
    }

    if (reached) 
        cout << "TAK\n" << cnt;
    else 
        cout << "NIE";
    
    return 0;
}
