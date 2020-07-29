#include <bits/stdc++.h>

using namespace std;

const int N = 601;

int memo[N][N];
bool vis[N][N];
int w[N], h[N];
int n;

int f(int dx, int dy) {
    if (dx == 0 || dy == 0) return 0;
    if (vis[dx][dy]) return memo[dx][dy];
    
    int ans = dx * dy;
    for (int i = 1; i <= n; i++) {
        if (w[i] > dx || h[i] > dy) continue;
        ans = min({
                    ans,
                    f(dx - w[i], dy) + f(w[i], dy - h[i]),
                    f(dx, dy - h[i]) + f(dx - w[i], h[i])
                });
    }

    memo[dx][dy] = ans;
    vis[dx][dy] = true;
    return ans;
}

int32_t main() {
    cin.tie(NULL)->sync_with_stdio(false);
    
    cin >> w[0] >> h[0] >> n;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> h[i];
    }

    cout << f(w[0], h[0]);

    return 0;
}
/*
21 11
4
10 4
6 2
7 5
15 10
*/
