// From: Dao Le Bao Minh
// Handle: minhle.ff / KozerG

// Note: somehow the "trace" version got 85
// and the "normal" version got 0

#include<bits/stdc++.h>
using namespace std;


int n, k;
int a[3001], c[3001];
int mem[3001][101];
pair<int, int> trace[3001][101];


int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    for(int i = 1; i <= n; ++i)
        cin >> c[i];
    mem[1][0] = a[1];
    for(int i = 1; i < n; ++i)
        for(int j = 0; j <= k; ++j)
            if(mem[i][j])
            for(int l = 1; l <= min(c[i], n - i); ++l)
                if(mem[i][j] + a[i + l] > mem[i + l][j + 1])
                    mem[i + l][j + 1] = mem[i][j] + a[i + l],
                    trace[i + l][j + 1] = {i, j};
    cout << mem[n][k + 1] << ' ';
    stack<int> s;
    for(int i = trace[n][k + 1].first, j = trace[n][k + 1].second, t; i != 1; t = i, i = trace[i][j].first, j = trace[t][j].second)
        s.push(i);
    for(cout << s.size() << '\n'; !s.empty(); s.pop())
        cout << s.top() << ' ';
}

