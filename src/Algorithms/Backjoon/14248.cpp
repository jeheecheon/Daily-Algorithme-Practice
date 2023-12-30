#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int diffX[4] = { 0, 1, 0, -1 };
int diffY[4] = { 1, 0, -1, 0 };

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    int stones[n + 1];
    int dist[n + 1];
    fill(&dist[0], &dist[0] + n + 1, -1);

    for (int i = 1; i <= n; ++i) {
        cin >> stones[i];
    }

    int s;
    cin >> s;

    queue<int> Q;
    Q.push(s);
    dist[s] = 1;
    int cnt = 1;
    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();

        for (int nextStone : {cur + stones[cur], cur - stones[cur]}) {
            if (nextStone <= 0 or nextStone > n)
                continue;
            if (dist[nextStone] != -1)
                continue;

            dist[nextStone] = 1;
            ++cnt;
            Q.push(nextStone);
        }
    }

    cout << cnt;
    return 0;
}
