#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 1;
const int MAX = 101;

int a[N], t[N];
int memo[N][MAX];
bool vis[N][MAX];
int n, T, D;

int solve(int i, int time) {
    if (vis[i][time]) return memo[i][time];
    if (time == t[i]) memo[i][time] = a[i];

    int ans = 0;
    for (int j = 1; j <= min(i - 1, D); j++) {
        if (time < t[i]) continue;
        ans = max(ans, solve(i - j, time - t[i]) + a[i]);
    }

    memo[i][time] = ans;
    vis[i][time] = true;
    return ans;

}

int32_t main() {
    cin.tie(NULL)->sync_with_stdio(false);
    
    cin >> n >> T >> D;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = t[i]; j <= T; j++) {
            ans = max(ans, solve(i, j));
        }
    }
    
    cout << ans;

    return 0;
}
/*
6 6 2
6 8 5 10 11 6
1 2 2 3 3 2
*/

