#include <bits/stdc++.h>

using namespace std;

#ifndef LOCAL
ifstream fi("QUALITY.inp");
ofstream fo("QUALITY.out");
#endif

const int N = 1e5 + 1;

int a[N];
int posleft[N], posright[N];
int mxleft, mxright;
int n;

int32_t main() {
    cin.tie(NULL)->sync_with_stdio(false);
    
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // for (int i = 1; i <= n; i++) {
    //     if (mxleft + 1 == a[i]) {
    //         posleft[++mxleft] = i;
    //     }
    // }

    // for (int i = n; i >= 1; i--) {
    //     if (mxright + 1 == a[i]) {
    //         posright[++mxright] = i;
    //     }
    // }

    // int mx = min(mxleft, mxright);

    // while (mx > 0) {
    //     if (posleft[mx] <= posright[mx]) break;
    //     --mx;
    // }

    // cout << mx;

    int i = 1;
    int j = n;
    int val = 1;

    while (i <= j) {
        if (a[i] != val && a[j] != val) ++i, --j;
        else if (a[j] != val) --j;
        else if (a[i] != val) ++i;
        else ++i, --j, ++val;
    }

    cout << val - 1;

    return 0;
}

