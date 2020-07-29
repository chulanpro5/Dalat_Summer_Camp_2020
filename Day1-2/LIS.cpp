#include <bits/stdc++.h>

using namespace std;

int32_t main() {
    cin.tie(NULL)->sync_with_stdio(false);
    
    int n;
    cin >> n;

    vector<int> a;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;

        auto it = lower_bound(a.begin(), a.end(), x);
        if (it == a.end()) {
            a.push_back(x);
        }
        else {
            *it = x;
        }
    }

    cout << a.size() << '\n';

    return 0;
}


