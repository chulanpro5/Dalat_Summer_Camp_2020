#include <bits/stdc++.h>

using namespace std;

#ifndef LOCAL
ifstream fi("CLUES.inp");
ofstream fo("CLUES.out");
#endif

int MOD;

int add(int a, int b) {
    return ((a % MOD) + (b % MOD)) % MOD;
}

int mul(int a, int b) {
    return (1LL * (a % MOD) * (b % MOD)) % MOD;
}

int power(int a, int b) {
    int ret = 1;

    while (b) {
        if (b % 2) ret = mul(ret, a);
        a = mul(a, a);
        b >>= 1;
    }

    return ret;
}

int n, m;

vector<vector<int>> g;
vector<bool> vis;
vector<int> sz;

int connected_components = 0;
int traversed = 0;

int DFS(int u) {
    vis[u] = true;
    ++traversed;

    for (int v : g[u]) {
        if (!vis[v]) DFS(v);
    }
}

int32_t main() {
    cin.tie(NULL)->sync_with_stdio(false);
    
    fi >> n >> m >> MOD;

    g.resize(n + 1);
    vis.resize(n + 1);
    sz.resize(n + 1);

    while (m--) {
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        traversed = 0;
        DFS(i);
        sz[connected_components++] = traversed;
    }

    int ans = 1;
    for (int i = 0; i < connected_components; i++) {
        ans = mul(ans, sz[i]);
    }

    ans = mul(ans, power(n, connected_components - 1));

    fo << ans;

    return 0;
}

