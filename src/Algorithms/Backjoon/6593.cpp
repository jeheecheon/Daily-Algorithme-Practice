#include <bits/stdc++.h>
using namespace std;

tuple<int, int, int> directions[6] = {{0, 0, 1}, {0, -1, 0}, {0, 0, -1}, {0, 1, 0}, {1, 0, 0}, {-1, 0, 0}};
char building[30][30][30];
int dist[30][30][30];
int L, R, C;

void BFS(queue<tuple<int, int, int>>& Q) {
    while (!Q.empty()) {
        auto cur = Q.front(); Q.pop();

        for (auto& nextDir : directions) {
            int nl = get<0>(nextDir) + get<0>(cur),
            nr = get<1>(nextDir) + get<1>(cur),
            nc = get<2>(nextDir) + get<2>(cur);
            if (nl < 0 || nl >= L || nr < 0 || nr >= R || nc < 0 || nc >= C
                || dist[nl][nr][nc] >= 0)
                continue;

            if (building[nl][nr][nc] == '.') {
                dist[nl][nr][nc] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
                Q.push({nl, nr, nc});
            }
            if (building[nl][nr][nc] == 'E') {
                cout << "Escaped in " << dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1 << " minute(s).\n";
                return;
            }
        }
    }
    cout << "Trapped!\n";
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while(true) {
        cin >> L >> R >> C;
        if (!L || !R || !C)
            return 0;

        fill(&dist[0][0][0], &dist[0][0][0] + sizeof(dist) / sizeof(int), -1);

        queue<tuple<int, int, int>> Q;
        for (int l = 0; l < L; ++l) {
            for (int r = 0; r < R; ++r) {
                for (int c = 0; c < C; ++c) {
                    cin >> building[l][r][c];
                    if (building[l][r][c] == 'S') {
                        dist[l][r][c] = 0;
                        Q.push({l, r, c});
                    }
                }
            }
        }

        BFS(Q); 
    }
}
