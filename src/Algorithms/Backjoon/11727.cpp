// https://www.acmicpc.net/problem/11727
// Title: 2×n 타일링 2

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> mem(n + 1);
    mem[0] = 1;
    mem[1] = 3;

    for (int i = 2; i < n; ++i) mem[i] = (mem[i - 1] + mem[i - 2] * 2) % 10007;

    cout << mem[n - 1] << endl;

    return 0;
}