#include <bits/stdc++.h>

using namespace std;

int32_t main() {
#ifndef LOCAL
    freopen("SANDSTORM.inp", "r", stdin);
    freopen("SANDSTORM.out", "w", stdout);
#endif
    cin.tie(NULL)->sync_with_stdio(false);
 
    long long a, b;
    cin >> a >> b;
    cout << (b - a - 1) * (b - a) / 2;

    return 0;
}

