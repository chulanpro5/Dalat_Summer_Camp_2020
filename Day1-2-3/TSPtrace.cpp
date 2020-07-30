#include <bits/stdc++.h>

using namespace std;

// ====================================================================
string to_string(string s){return '"'+s+'"';}
string to_string(const char* s){return to_string((string)s);}
string to_string(bool b){return (b?"true":"false");}
template<typename A,typename B>string to_string(pair<A,B> p){return '('+to_string(p.first)+", "+ to_string(p.second)+')';}
template<typename A>string to_string(A v){bool first=1;string res="{";for(const auto &x:v){if(!first){res += ", ";}first=0;res+=to_string(x);}res += '}';return res;}
void dbo(){cerr<<endl;} template<typename _H,typename... _T>void dbo(_H H,_T... T){cerr<<' '<<to_string(H);dbo(T...);}
#ifdef LOCAL
#define debug(...) cerr<<'['<<#__VA_ARGS__<<"]:",dbo(__VA_ARGS__)
#else
#define debug(...) "Hikarii"
#endif
// ====================================================================

const int N = 22;
const int INF = 1e9;
int FULLSET;

int cost[N][N];
int memo[N][1 << N];
bool vis[N][1 << N];
int n, m;

int f(int i, int mask) {

    if (mask == FULLSET) return cost[i][1];
    
    if (vis[i][mask]) return memo[i][mask];

    int ans = INF;
    
    for (int j = 1; j <= n; j++) {
        if ((mask >> j & 1) == 0) {
            ans = min(ans, f(j, mask | (1 << j)) + cost[i][j]);
        }
    }

    vis[i][mask] = true;
    return memo[i][mask] = ans;

}

int32_t main() {
    cin.tie(NULL)->sync_with_stdio(false);
   
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        FULLSET |= (1 << i);
    }

    while (m--) {
        int u, v, c;
        cin >> u >> v >> c;
        cost[u][v] = c;
    }

    cout << f(1, 1 << 1);

    return 0;
}
/*
3 4
1 2 3
2 1 10
2 3 1
3 1 2
*/

