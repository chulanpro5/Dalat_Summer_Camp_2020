#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main() {
#ifndef LOCAL
    freopen("SIDEWALK.inp", "r", stdin);
    freopen("SIDEWALK.out", "w", stdout);
#endif
    cin.tie(NULL)->sync_with_stdio(false);
 
    int n, m, k;
    cin >> n >> m >> k;

    int ans = 0;

    while (k - (2 * (n + m) - 4) >= 0 && n - 2 >= 0 && m - 2 >= 0) {
        k -= (2 * (n + m) - 4);
        ++ans; n -= 2; m -= 2;
    }

    cout << ans;

    return 0;
}

