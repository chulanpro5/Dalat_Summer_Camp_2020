#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 1;
int a[N], b[N];
int dp[N][N], trace[N];
int n, m;

int32_t main() {
    cin.tie(NULL)->sync_with_stdio(false);
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (a[i] == b[j]) {
                dp[i][j] = max(dp[i][j], 1 + dp[i - 1][j - 1]);
            }
        }
    } 

    cout << dp[n][m] << '\n';
    
    stack<int> st;
    while (dp[n][m]) {
        while (dp[n][m] == dp[n][m - 1]) --m;
        while (dp[n][m] == dp[n - 1][m]) --n;
        st.push(a[n]);
        n--; m--;
    }

    while (!st.empty()) {
        cout << st.top() << ' ';
        st.pop();
    }

    return 0;
}
/*
7
3 7 2 5 1 4 9
10
4 3 2 3 6 1 5 4 9 7
*/

