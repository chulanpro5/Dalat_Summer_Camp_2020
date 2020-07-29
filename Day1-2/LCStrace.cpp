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

const int N = 1e3 + 1;
int a[N], b[N];
int dp[N][N], trace[N];
int n, m;

int32_t main() {
    cin.tie(NULL)->sync_with_stdio(false);
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i] == b[j]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
            // trace[i] = max(dp[i][j], trace[i]);
        }
    } 

    // int p = max(trace + 1, trace + n + 1) - trace;
    // for(int i = 1; i <= n; i++)
        // debug(i, trace[i]);
    // for(int i = p - trace[p] + 1; i <= p; i++)
        // cout << a[i];

    cout << dp[n][m] << '\n';
    
    stack<int> st;
    while (dp[n][m]) {
        while (dp[n][m] == dp[n][m - 1]) --m;
        while (dp[n][m] == dp[n - 1][m]) --n;
        st.push(a[n]);
        n--; m--;
    }
    // while ()

    while (!st.empty()) {
        cout << st.top() << ' ';
        st.pop();
    }

    return 0;
}
/*
7
3 7 2 5 1 4 9
10
4 3 2 3 6 1 5 4 9 7
*/

