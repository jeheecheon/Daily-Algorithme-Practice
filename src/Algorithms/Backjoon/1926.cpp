#include <bits/stdc++.h>
using namespace std;

int diffX[4] = { 0, 1, 0, -1 };
int diffY[4] = { 1, 0, -1, 0, };

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    int board[n][m];
    bool visited[n][m];
    fill(&visited[0][0], &visited[0][0] + n * m, false);
    for (int x = 0; x < n; ++x)
        for (int y = 0; y < m; ++y) 
            cin >> board[x][y];

    int paints = 0;
    int biggestOne = 0;
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < m; ++y) {
            if (board[x][y] and visited[x][y] == false) {
                // start BFS
                ++paints;

                queue<pair<int, int>> Q;

                Q.push({x, y});
                visited[x][y] = true;
                int sizeOfPaint = 1;

                while(!Q.empty()) {
                    pair<int, int> curPos = Q.front(); 
                    Q.pop();

                    for (int iter = 0; iter < 4; ++iter) {
                        int adjX = curPos.first + diffX[iter];
                        int adjY = curPos.second + diffY[iter];

                        // Check if the adjacent pos is in the size of board
                        if (adjX < 0 or adjX >= n or adjY < 0 or adjY >= m)
                            continue;
                        
                        // Check if the adjacent pos is alrady visited and an valid path
                        if (visited[adjX][adjY] or board[adjX][adjY] == 0)
                            continue;

                        Q.push({adjX, adjY});
                        visited[adjX][adjY] = true;
                        ++sizeOfPaint;
                    }
                }
                if (sizeOfPaint > biggestOne)
                    biggestOne = sizeOfPaint;
            }
        }
    }  

    // Print the answer
    cout << paints << '\n' << biggestOne;  
    return 0;
}