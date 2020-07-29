#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 1e5 + 1;
const int INF = 1e18;

int n, l1, l2;
int a[N], dp[N];
int T[N << 2];

void build(int i = 1, int l = 1, int r = n) {
    if (l == r) T[i] = a[l];
    else {
        int m = (l + r) / 2;
        build(i << 1, l, m);
        build(i << 1 | 1, m + 1, r);
        T[i] = max(T[i << 1], T[i << 1 | 1]);
    }
}

void update(int p, int val, int i = 1, int l = 1, int r = n) {
    if (p < l || r < p) return;

    if (l == p && p == r) {
        a[p] = val;
        T[i] = val;
    }
    else {
        int m = (l + r) / 2;
        if (p <= m) update(p, val, i << 1, l, m);
        else update(p, val, i << 1 | 1, m + 1, r);
        T[i] = max(T[i << 1], T[i << 1 | 1]);
    }
}

int get(int u, int v, int i = 1, int l = 1, int r = n) {
    if (v < l || r < u) return -INF;
    
    if (u <= l && r <= v) return T[i];
    else {
        int m = (l + r) / 2;
        int left = get(u, v, i << 1, l, m);
        int right = get(u, v, i << 1 | 1, m + 1, r);

        return max(left, right);
    }
}

int32_t main() {
    cin.tie(NULL)->sync_with_stdio(false);
 
    cin >> n >> l1 >> l2;
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    build();

    int ans = -INF;
    for (int i = 1; i <= n; i++) {
        int left = max(i - l2, 1LL);
        int right = max(i - l1, 1LL);
        int mx = get(left, right);
        if (mx >= 0) {
            update(i, a[i] + mx);
        }

        ans = max(ans, dp[i]);
    }

    cout << ans;

    return 0;
}
/*
6 2 3
3 5 9 6 7 4
*/

