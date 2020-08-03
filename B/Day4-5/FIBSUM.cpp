#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int MOD = 1e9;

int mul(int a, int b) {
    return ((a % MOD) * (b % MOD)) % MOD;
}

int add(int a, int b) {
    return ((a % MOD) + (b % MOD)) % MOD;
}

vector<vector<int>> mul(vector<vector<int>> a, vector<vector<int>> b) {
    vector<vector<int>> ret(2, vector<int>(2));

    ret[0][0] = add(mul(a[0][0], b[0][0]), mul(a[0][1], b[1][0]));
    ret[0][1] = add(mul(a[0][0], b[1][0]), mul(a[0][1], b[1][1]));

    ret[1][0] = add(mul(a[1][0], b[0][0]), mul(a[1][1], b[1][0]));
    ret[1][1] = add(mul(a[1][0], b[1][0]), mul(a[1][1], b[1][1]));

    return ret;
}


vector<vector<int>> power(vector<vector<int>> a, int b) {
    if (b == 1) return a;
 
    vector<vector<int>> temp = power(a, b / 2);

    if (b % 2) return mul(mul(temp, temp), a);
    else return mul(temp, temp);
}

int getfib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    vector<vector<int>> def = {{0, 1}, {1, 1}};
    def = power(def, n - 1);
    return def[1][1] % MOD;
}

int32_t main() {
#ifndef LOCAL
    ifstream fi("FIBSUM.inp");
    ofstream fo("FIBSUM.out");
#endif
    cin.tie(NULL)->sync_with_stdio(false);

    int a, b;
    while (fi >> a >> b) {
        if (a == b) fo << getfib(a) << '\n';
        else fo << getfib(b + 3) - getfib(a + 2) << '\n';
    }

    return 0;
}

