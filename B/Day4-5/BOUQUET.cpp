#include <bits/stdc++.h>

using namespace std;

int32_t main() {
#ifndef LOCAL
    freopen("BOUQUET.inp", "r", stdin);
    freopen("BOUQUET.out", "w", stdout);
#endif
    cin.tie(NULL)->sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int &i : a) cin >> i;

    int ans = 0;

    if (n % 2) {
        for (int i : a) {
            ans += i - (i % 2 == 0);
        }
    }
    else {
        int mn = 1e9;
        for (int i : a) mn = min(mn, i);
        for (int i : a) {
            if (i == mn) continue;
            ans += i - (i % 2 == 0);
        }
    }

    cout << ans;

    return 0;
}

