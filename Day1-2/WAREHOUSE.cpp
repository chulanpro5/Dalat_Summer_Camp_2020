// From: Tran Quoc Phong GL
// Handle: National_Wind
#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 1e3 + 1;
const int MAX = 101;

int n, T, D;
int a[N], t[N], f[N][MAX];
int res, pos;
bool vis[N][MAX];
vector<int> ans;

int dp(int i, int j) {
    if (j == t[i]) {
        if (res < f[i][j]) {
            res = f[i][j];
            pos = i;
        }
        return f[i][j] = a[i];
    }

    if (j < t[i]) return 0;
    if (vis[i][j]) return f[i][j];
    for (int k = i - 1; k >= 0 && i - k <= D; k--) {
        f[i][j] = max(f[i][j], dp(k, j - t[i]) + a[i]);
    }

    if (res < f[i][j]) {
        res = f[i][j];
        pos = i;
    }

    vis[i][j] = true;
    return f[i][j];
}

int32_t main() {
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> n >> T >> D;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> t[i];
    for (int i = 1; i <= n; i++) dp(i, T);
    cout << res << ' ';
    return 0;
}

