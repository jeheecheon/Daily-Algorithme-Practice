#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int F, S, G, U, D;
    cin >> F >> S >> G >> U >> D;

    int floors[F + 1];
    fill(&floors[0], &floors[0] + F + 1, -1);

    queue<int> Q;
    Q.push(S);
    floors[S] = 0;

    while(!Q.empty()) {
        int currentFloor = Q.front();
        Q.pop();

        for (int nextFloor : { currentFloor + U, currentFloor - D}) {
            if (currentFloor == nextFloor or nextFloor < 1 or nextFloor > F or floors[nextFloor] != -1)
                continue;

            floors[nextFloor] = floors[currentFloor] + 1;
            Q.push(nextFloor);
        }
    } 
    
    if(floors[G] == -1) 
        cout << "use the stairs";
    else 
        cout << floors[G];

    return 0;
}