#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 1e6 + 1;

int n, l1, l2;
int a[N], dp[N];

int32_t main() {
    cin.tie(NULL)->sync_with_stdio(false);
    
    cin >> n >> l1 >> l2;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        dp[i] = a[i];
    }

    multiset<int> mts;
    mts.insert(0);
    int ans = -1e18;
    bool zero_exist = true;

    for (int i = l1; i <= n; i++) {
        if (i - l2 >= 0) {
            if (zero_exist) {
                mts.erase(mts.find(0));
                zero_exist = false;
            }
        }

        if (i - l1 >= 0) mts.insert(dp[i - l1]);
        ans = max(ans, dp[i] - *mts.begin());

        if (i - l2 >= 0) {
            mts.erase(mts.find(sum[i - l2]));
        }
    }

    cout << ans;

    return 0;
}
/*
6   3  4
3  5 -9  6  7  -4
*/

