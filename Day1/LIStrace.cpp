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

int32_t main() {
    cin.tie(NULL)->sync_with_stdio(false);
    
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &i : a) cin >> i;

    vector<int> lis;
    for (int i : a) {
        auto it = lower_bound(lis.begin(), lis.end(), i);
        if (it == lis.end()) lis.push_back(i);
        else *it = i;
    }

    cout << lis.size() << '\n';

    int p = 0;
    for (int i : lis) {
        while (a[p] != i) ++p;
        cout << p + 1 << ' ';
    }

    return 0;
}

