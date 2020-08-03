#include <bits/stdc++.h>

using namespace std;

// ====================================================================
void read(){return;} void writesp(){return;} void writeln(){return;}
template<typename T>void write(T x){if(x<0){putchar('-');x=-x;}char buf[20],*p=buf;do{*p++='0'+x%10;x/=10;}while(x);do{putchar(*--p);}while(p>buf);}
template<typename T>void _wiln_(T x){write(x);putchar('\n');}
template<typename T>void _wisp_(T x){write(x);putchar(' ');}
template<typename _H,typename... _T>void writesp(_H H,_T... T){_wisp_(H);writesp(T...);}
template<typename _H,typename... _T>void writeln(_H H,_T... T){_wiln_(H);writeln(T...);}
template<typename T>void _ri_(T &x){char c;while(c=getchar(),c<=' ');bool sign=c=='-';if(sign)c=getchar();x=c-'0';while(c=getchar(),c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c-'0');}if(sign)x=-x;}
template<typename _H,typename... _T>void read(_H& H,_T&... T){_ri_(H);read(T...);}
// ====================================================================

const int N = 22;
const int INF = 1e9;
int FULLSET;

int cost[N][N];
int memo[N][1 << N];
bool vis[N][1 << N];
int n, m;

int f(int i, int mask) {
    if (vis[i][mask]) return memo[i][mask];
    if (mask == FULLSET) {
        vis[i][mask] = true;
        return memo[i][mask] = cost[i][1];
    }
    
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
   
    read(n, m);

    for (int i = 1; i <= n; i++) {
        FULLSET |= (1 << i);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cost[i][j] = INF;
        }
    }

    while (m--) {
        int u, v, c;
        read(u, v, c);
        cost[u][v] = c;
    }

    writeln(f(1, 1 << 1));

    vector<int> ans = {1};

    for (int i = 1, mask = 1 << 1, k = 0; k < n - 1; k++) {
        for (int j = 1; j <= n; j++) {
            if ((mask >> j & 1) == 0 && memo[i][mask] == cost[i][j] + memo[j][mask | (1 << j)]) {
                ans.push_back(j);
                i = j;
                mask |= (1 << j);
            }
        }
    }

    for (int i : ans) writesp(i);

    return 0;
}
/*
3 4
1 3 3
3 1 10
3 2 1
2 1 2
*/

