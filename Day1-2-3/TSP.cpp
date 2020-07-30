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

    return 0;
}
/*
3 4
1 3 3
3 1 10
3 2 1
2 1 2
*/
