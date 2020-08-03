#include <bits/stdc++.h>

using namespace std;

int32_t main() {
#ifndef LOCAL
    freopen("TROIKA.inp", "r", stdin);
    freopen("TROIKA.out", "w", stdout);
#endif
    cin.tie(NULL)->sync_with_stdio(false);
 
    int n;
    cin >> n;

    int k = 1;
    int p = 2;
    long long ans = 0;
    set<int> s;

    s.insert(p * p);

    while (n / k >= 9) {
        if (k == p * p) {
            ++p; ++k;
            s.insert(p * p);
            continue;
        }

        bool fig = true;
        for (int i : s) {
            if (k % i == 0) {
                ++k; fig = false;
                break;
            }
        }

        if (!fig) continue;
        
        int q = floor(sqrt(n / k)) + 1;
        if (q * q > n / k) --q;
        ans += 1LL * q * (q - 1) * (q - 2) / 6;
        ++k;
    }

    cout << ans;

    return 0;
}

