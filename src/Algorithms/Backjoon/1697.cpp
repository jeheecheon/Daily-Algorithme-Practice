#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;    

    cin >> N >> K;
    
    int dist[100002];
    fill(dist, dist + 100002, -1);
    dist[N] = 0;
    queue<int> Q;
    Q.push(N);

    while(dist[K] == -1) {
        int current = Q.front();
        Q.pop();

        for (int next : {current - 1, current + 1, current * 2}) {
            if (next < 0 or next > 100000)
                continue;
            if (dist[next] != -1)
                continue;
            
            dist[next] = dist[current] + 1;
            Q.push(next);
        }
    }
    
    cout << dist[K];

    return 0;
}