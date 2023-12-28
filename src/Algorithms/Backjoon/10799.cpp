#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    stack<char> st;
    
    string braces;
    cin >> braces;

    bool wasOpenBrace = false;
    int cnt = 0;
    for (auto b : braces) {
        if (b == '(') {
            ++cnt;
            st.push(b);
            wasOpenBrace = true;
        }
        else {
            st.pop();
            if (wasOpenBrace) {
                --cnt;
                cnt += st.size();
            }
            wasOpenBrace = false;
        }
    }

    cout << cnt << '\n';

    return 0;
}