// From: Tran Quoc Phong GL
// Handle: National_Wind
#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 1;
const int INF = 1e9;

int memo[N][N], type[N][N];
bool vis[N][N];
string a, b;
vector<pair<int, int>> res;

int LCS(int i, int j) {
    if (i == 0) {
        memo[i][j] = j;
        type[i][j] = 3;
        return memo[i][j];
    }
    if (j == 0) {
        memo[i][j] = i;
        type[i][j] = 2;
        return memo[i][j];
    }
    if (vis[i][j]) return memo[i][j];
    if (a[i] == b[j]) memo[i][j] = min(memo[i][j], LCS(i - 1, j - 1));
    else {
        if (memo[i][j] > LCS(i - 1, j - 1) + 1) {
            memo[i][j] = LCS(i - 1, j - 1) + 1;
            type[i][j] = 1;
        }
    }
    if (memo[i][j] > LCS(i - 1, j) + 1) {
        memo[i][j] = LCS(i - 1, j) + 1;
        type[i][j] = 2;
    }
    if (memo[i][j] > LCS(i, j - 1) + 1) {
        memo[i][j] = LCS(i, j - 1) + 1;
        type[i][j] = 3;
    }
    vis[i][j] = 1;
    return memo[i][j];
}

void trace(int i, int j) {
    if (i == 0 && j == 0) return;
    if (type[i][j] == 0) {
        trace(i - 1, j - 1);
    }
    if (type[i][j] == 1) {
        cout << "REPLACE " << i << ' ' << b[j] << '\n';
        trace(i - 1, j - 1);
    }
    if (type[i][j] == 2) {
        cout << "DELETE " << i << '\n';
        trace(i - 1, j);
    }
    if (type[i][j] == 3) {
        cout << "INSERT " << i + 1 << ' ' << b[j] << '\n';
        trace(i, j - 1);
    }
}

int32_t main() {
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> a >> b;

    int n = a.size();
    int m = b.size();
    a = ' ' + a;
    b = ' ' + b;
    
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            memo[i][j] = INF;
        }
    }

    cout << LCS(n, m) << '\n';
    trace(n, m);
    
    return 0;
}

