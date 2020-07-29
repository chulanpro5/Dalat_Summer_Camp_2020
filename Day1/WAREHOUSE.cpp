#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 1;
const int MAX = 101;

int a[N], t[N], opttime[N];
int dp[N][MAX];
int n, T, D;

int32_t main() {
    cin.tie(NULL)->sync_with_stdio(false);
    
    cin >> n >> T >> D;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
    }

    for (int i = 1; i <= n; i++) {
        dp[i][t[i]] = a[i];
        opttime[i] = t[i];

        for (int j = max(1, i - D); j < i; j++) {
            if (opttime[i] + t[j] <= )
        }
    }
   
    return 0;
}
/*
6 6 2
6 8 5 10 11 6
1 2 2 3 3 2
*/

