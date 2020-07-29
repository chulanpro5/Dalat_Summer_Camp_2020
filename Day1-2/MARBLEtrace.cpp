// From: Dao Le Bao Minh KT
// Handle: minhle.ff / KozerG
#include <bits/stdc++.h>
using namespace std;


int n;
int W[201], H[201];
int mem[601][601];
struct cut{
    int x, y, t, k;
};
pair<int, int> trace[601][601][2];
cut trct[601][601][2];
bool d[601][601];



int f(int dx, int dy){
    if(dx == 0 || dy == 0)
        return 0;
    if(d[dx][dy])
        return mem[dx][dy];
    int ans = dx*dy;
    for(int i = 1; i <= n; i++)
        if(W[i] <= dx && H[i] <= dy){
            if(ans > f(dx, dy - H[i]) + f(dx - W[i], H[i]))
                ans = f(dx, dy - H[i]) + f(dx - W[i], H[i]),
                trace[dx][dy][0] = {dx, dy - H[i]},
                trct[dx][dy][0] = {dx, dy, 1, H[i]},
                trace[dx][dy][1] = {dx - W[i], H[i]},
                trct[dx][dy][1] = {dx, H[i], 0, W[i]};
            if(ans > f(dx - W[i], dy) + f(W[i], dy - H[i]))
                ans = f(dx - W[i], dy) + f(W[i], dy - H[i]),
                trace[dx][dy][0] = {dx - W[i], dy},
                trct[dx][dy][0] = {dx, dy, 0, W[i]},
                trace[dx][dy][1] = {W[i], dy - H[i]},
                trct[dx][dy][1] = {W[i], dy, 1, H[i]};
            }
    d[dx][dy] = 1;
    return mem[dx][dy] = ans;   
}


int main(){
    cin >> W[0] >> H[0] >> n;
    for(int i = 1; i <= n; i++)
        cin >> W[i] >> H[i];
    cout << f(W[0], H[0]) << '\n';
    vector<pair<int, int>> s = {{W[0], H[0]}};
    for(int i = 0; i < s.size(); i++)
        if(f(s[i].first, s[i].second) == s[i].first*s[i].second){
            if(s[i].first == 1){
                if(s[i].second != 1)
                    s.push_back({s[i].first, s[i].second - 1});
            }
            else if(s[i].second == 1){
                if(s[i].first != 1)
                    s.push_back({s[i].first - 1, s[i].second});
            }
            else 
                s.push_back({s[i].first - 1, s[i].second}),
                s.push_back({1, s[i].second - 1});
        }
        else{
            int dx0 = trace[s[i].first][s[i].second][0].first,
                dy0 = trace[s[i].first][s[i].second][0].second,
                dx1 = trace[s[i].first][s[i].second][1].first,
                dy1 = trace[s[i].first][s[i].second][1].second;
            if(dx0 != 0 && dy0 != 0) s.push_back({dx0, dy0});
            if(dx1 != 0 && dy1 != 0) s.push_back({dx1, dy1});
        }
    cout << s.size() - 1 << '\n';
    s = {{W[0], H[0]}};
    for(int i = 0; i < s.size(); i++)
        if(f(s[i].first, s[i].second) == s[i].first*s[i].second){
            if(s[i].first == 1){
                if(s[i].second != 1){
                    s.push_back({s[i].first, s[i].second - 1});
                    cout << s[i].first << ' ' << s[i].second << " 1 1\n";
                }
            }
            else if(s[i].second == 1){
                if(s[i].first != 1){
                    s.push_back({s[i].first - 1, s[i].second});
                    cout << s[i].first << ' ' << s[i].second << " 0 1\n";
                }
            }
            else{
                s.push_back({s[i].first - 1, s[i].second}),
                cout << s[i].first << ' ' << s[i].second << " 0 1\n";
                s.push_back({1, s[i].second - 1});
                cout << "1 " << s[i].second << " 1 1\n";
            }
        }
        else{
            int dx0 = trace[s[i].first][s[i].second][0].first,
                dy0 = trace[s[i].first][s[i].second][0].second,
                dx1 = trace[s[i].first][s[i].second][1].first,
                dy1 = trace[s[i].first][s[i].second][1].second;
            if(dx0 != 0 && dy0 != 0){
                s.push_back({dx0, dy0});
                cout << trct[s[i].first][s[i].second][0].x << ' ' << trct[s[i].first][s[i].second][0].y << ' ' << trct[s[i].first][s[i].second][0].t << ' ' << trct[s[i].first][s[i].second][0].k << '\n';
            }
            if(dx1 != 0 && dy1 != 0){
                s.push_back({dx1, dy1});
                cout << trct[s[i].first][s[i].second][1].x << ' ' << trct[s[i].first][s[i].second][1].y << ' ' << trct[s[i].first][s[i].second][1].t << ' ' << trct[s[i].first][s[i].second][1].k << '\n';
            }
        }
}

