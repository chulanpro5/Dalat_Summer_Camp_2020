#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 1e5 + 1;

int n, l1, l2;
int a[N], dp[N];
bool vis[N];

int32_t main() {
    cin.tie(NULL)->sync_with_stdio(false);
 
    cin >> n >> l1 >> l2;
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= l1; i++) {
        dp[i] = a[i];
    }

    for (int i = l1 + 1; i <= n; i++) {
        int mx = 0;
        for (int j = l1; j <= l2; j++) {
            if (i - j < 0) break;
            mx = max(mx, dp[i - j]);
        }
        dp[i] = a[i] + mx;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dp[i]);
    }

    cout << ans;

    return 0;
}
/*
6 2 3
3 5 9 6 7 4
*/

