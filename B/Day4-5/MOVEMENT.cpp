#include <bits/stdc++.h>

using namespace std;

int32_t main() {
#ifndef LOCAL
    freopen("MOVEMENT.inp", "r", stdin);
    freopen("MOVEMENT.out", "w", stdout);
#endif
    cin.tie(NULL)->sync_with_stdio(false);
    
    int a, b, n;
    cin >> a >> b >> n;

    int ans = 0;
    
    ans += 2 * ((n - b) / (b - a)) + 1;
    int rem = (n - b % (b - a);

    if (rem != 0) ans += 2

    cout << ans;

    return 0;
}

