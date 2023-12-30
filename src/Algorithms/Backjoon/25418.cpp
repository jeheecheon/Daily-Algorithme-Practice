#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int diffX[4] = { 0, 1, 0, -1 };
int diffY[4] = { 1, 0, -1, 0 };

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int A, K;
    cin >> A >> K;

    int nums[K + 1];
    fill(&nums[0], &nums[0] + K + 1, -1);

    queue<int> Q;
    Q.push(A);
    nums[A] = 0;

    while (!Q.empty()) {
        int cur = Q.front(); Q.pop();

        for (int nextNum : {cur + 1, cur * 2}) {
            if (nextNum > K)
                continue;
            if (nums[nextNum] != -1)
                continue;

            nums[nextNum] = nums[cur] + 1;
            Q.push(nextNum);
        }
    }

    cout << nums[K];
    return 0;
}
