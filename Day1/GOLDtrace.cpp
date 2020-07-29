#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 1e5 + 1;

int n, l1, l2;
int a[N], dp[N], trace[N];
bool vis[N];

int32_t main() {
    cin.tie(NULL)->sync_with_stdio(false);
 
    cin >> n >> l1 >> l2;
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= l1; i++) {
        dp[i] = a[i];
    }

    for (int i = l1 + 1; i <= n; i++) {
        int mx = 0;
        int p = 0;
        for (int j = l1; j <= l2; j++) {
            if (i - j < 0) break;
            if (mx < dp[i - j]) {
                mx = dp[i - j];
                p = i - j;
            }
        }
        dp[i] = a[i] + mx;
        trace[i] = p;
    }

    int ans = 0;
    int p = 0;

    for (int i = 1; i <= n; i++) {
        if (ans < dp[i]) {
            ans = dp[i];
            p = i;
        }
    }

    stack<int> st;
    for (int i = p; i != 0; i = trace[i]) {
        st.push(i);
    }
    
    cout << ans << ' ' << st.size() << '\n';
    while (!st.empty()) {
        cout << st.top() << ' ';
        st.pop();
    }

    return 0;
}
/*
6 2 3
3 5 9 6 7 4
*/

