#include <bits/stdc++.h>

using namespace std;

int n;

vector<int> prufcode;

void prufdecode() {
    vector<int> degree(n, 1);
    for (int i : prufcode) ++degree[i];

    int p = 0;
    while (degree[p] != 1) ++p;

    int 
}

int32_t main() {
    cin.tie(NULL)->sync_with_stdio(false);
    
    cin >> n;
    n += 2;

    prufcode.resize(n - 2);
    for (int &i : prufcode) cin >> i;

    prufdecode();

    return 0;
}

