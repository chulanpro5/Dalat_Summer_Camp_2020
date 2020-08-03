#include <bits/stdc++.h>

using namespace std;

int32_t main() {
#ifndef LOCAL
    ifstream cin("ENERGY.inp");
    ofstream cout("ENERGY.out");
#endif
    cin.tie(NULL)->sync_with_stdio(false);

    int n;
    cin >> n;

    long long ans = 0;
    priority_queue<long long> a, p;

    for (int i = 0; i < 2 * n; i++) {
        int x, y;
        cin >> x >> y;

        if (x >= y) {
            ans += y;
            a.push(x - y);
        }
        else {
            ans += x;
            p.push(y - x);
        }
    }

    int na = a.size();
    int np = p.size();

    for (int i = 0; i < min(n, na); i++) {
        ans += a.top();
        a.pop();
    }

    for (int i = 0; i < min(n, np); i++) {
        ans += p.top();
        p.pop();
    }

    cout << ans;

    return 0;
}

