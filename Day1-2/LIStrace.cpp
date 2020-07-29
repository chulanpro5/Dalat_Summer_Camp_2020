#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;
const int INF = 1e9;

int a[N + 2], l[N + 2], pre[N + 2];

int32_t main() {
    cin.tie(NULL)->sync_with_stdio(false);
    
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    fill(l, l + N + 2, INF);

    a[0] = -INF;
    a[n + 1] = INF;
    l[0] = 0;

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        int pos = lower_bound(l, l + N + 2, a[i]) - l;
        l[pos] = a[i];
        pre[i] = pos;
        ans = max(ans, pos);
    }

    vector<int> ord;
    for (int i = n, exp = ans; i >= 0; i--) {
        if (pre[i] == exp) {
            ord.push_back(i);
            --exp;
        }
    }

    cout << ans << '\n';
    for (int i = (int) ord.size() - 2; i >= 0; i--) {
        cout << ord[i] << ' ';
    }

    return 0;
}

