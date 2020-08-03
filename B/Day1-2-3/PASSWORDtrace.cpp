#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 1;
int a[N], b[N];
int dp[N][N];

int32_t main() {
    cin.tie(NULL)->sync_with_stdio(false);
  
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (a[i] == b[j]) {
                if (i - 2 < 0 || j - 2 < 0) {
                    dp[i][j] = max(dp[i][j], 1);
                }
                else {
                    dp[i][j] = max(dp[i][j], 1 + dp[i - 2][j - 2]);
                }
            }
        }
    }

    cout << dp[n][m] << '\n';

    stack<int> st;
    while (dp[n][m] && n >= 0 && m >= 0) {
        while (dp[n][m] == dp[n][m - 1]) --m;
        while (dp[n][m] == dp[n - 1][m]) --n;
        st.push(a[n]);
        n -= 2; m -= 2;
    }

    while (!st.empty()) {
        cout << st.top() << ' ';
        st.pop();
    }

    return 0;
}
/*
4 5
4 9 2 4
1 9 7 3 4

10 10
9 5 9 1 3 1 3 4 5 3
4 2 3 4 3 4 3 9 4 9
*/

