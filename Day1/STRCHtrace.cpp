#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 1;

int memo[N][N];
string a, b;

int solve(int i, int j) {
    if (i == -1) return j + 1;
    if (j == -1) return i + 1;

    if (memo[i][j] != -1) return memo[i][j];

    int ans = min({solve(i, j - 1) + 1, solve(i - 1, j) + 1, solve(i - 1, j - 1) + (a[i] != b[j])}); 

    memo[i][j] = ans;
    return ans;
}



int32_t main() {
    cin.tie(NULL)->sync_with_stdio(false);
    
    cin >> a >> b;

    int n = a.size();
    int m = b.size();

    memset(memo, -1, sizeof(memo));
    cout << solve(n - 1, m - 1) << '\n';
   
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << memo[i][j] << '\t';
        }
        cout << '\n';
    }

    return 0;
}

