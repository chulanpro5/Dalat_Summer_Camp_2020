#include <bits/stdc++.h>

using namespace std;

#ifndef LOCAL
ifstream fi("EXCESS.inp");
ofstream fo("EXCESS.out");
#endif

string s;

bool is_palindrome(int i, int j) {
    while (i <= j && s[i] == s[j]) {
        ++i; --j;
    }

    return (i > j);
}

int32_t main() {
    cin.tie(NULL)->sync_with_stdio(false);
    
    fi >> s;

    int n = s.size();
    int l = 0;
    int r = n - 1;

    while (l <= r && s[l] == s[r]) {
        ++l; --r;
    }

    if (l > r) {
        fo << 0;
        return 0;
    }

    if (is_palindrome(l + 1, r)) fo << l;
    else if (is_palindrome(l, r - 1)) fo << r;
    else fo << 0;

    return 0;
}

