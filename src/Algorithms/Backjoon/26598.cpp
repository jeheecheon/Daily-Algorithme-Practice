#include <bits/stdc++.h>
using namespace std;

pair<int, int> diff1[4] = {
    {1, 0}, {0, 1}, {-1, 0}, {0, -1}
};

pair<int, int> diff2[4] = {
    {0, 1}, {-1, 0}, {0, -1}, {1, 0}
};

pair<int, int> betweenAdjsDiff[4] = {
    {1, 1}, {-1, 1}, {-1, -1}, {1, -1}
};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    string area[n];
    for (int i = 0; i < n; ++i)
        cin >> area[i];

    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < m; ++y) {
            for (int i = 0; i < 4; ++i) {
                int betweenAdjsX = betweenAdjsDiff[i].first + x, betweenAdjsY = y + betweenAdjsDiff[i].second;
                
                if (betweenAdjsX < 0 or betweenAdjsX >= n or betweenAdjsY < 0 or betweenAdjsY >= m)
                    continue;

                int adj1X = x + diff1[i].first, adj1Y = y + diff1[i].second;
                int adj2X = x + diff2[i].first, adj2Y = y + diff2[i].second;

                if (area[adj1X][adj1Y] == area[x][y] and
                    area[adj2X][adj2Y] == area[x][y] and 
                    area[betweenAdjsX][betweenAdjsY] != area[x][y]) {
                    cout << "BaboBabo";
                    return 0;
                }
            }
        }
    }
    
    cout << "dd";
    return 0;
}

