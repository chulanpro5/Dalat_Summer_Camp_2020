#include <bits/stdc++.h>

using namespace std;

int32_t main() {
#ifndef LOCAL
    freopen("ISOSCELE.inp", "r", stdin);
    freopen("ISOSCELE.out", "w", stdout);
#endif
    cin.tie(NULL)->sync_with_stdio(false);
 
    int n;
    cin >> n;

    long long ans = 1LL * n * (n - 1) / 2;
    if (n % 3 == 0) ans -= 2 * n / 3;

    cout << ans;

    return 0;
}


