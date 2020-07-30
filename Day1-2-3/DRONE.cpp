#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int N = 3e3 + 1;
const int K = 101;

int n, k;
int c[N], a[N];
int memo[N][K];
bool vis[N][K];

int dp(int i, int t) {
    if (t == 0) return c[i];
    
    if (vis[i][t]) return memo[i][t];
    
    memo[i][t] = c[i];
    int ans = 0;

    for (int j = 1; j < i; j++) {
        if (j + a[j] < i) continue;
        ans = max(ans, dp(j, t - 1) + c[i]);
    }

    vis[i][t] = true;
    memo[i][t] = ans;
    return ans;
}

int32_t main() {
    cin.tie(NULL)->sync_with_stdio(false);
    
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        cout << dp(i, k) << ' ';
    } 

    return 0;
}
/*
6 2
3 1 4 2 2 2
2 3 1 1 3 1
*/
