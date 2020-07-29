#include <bits/stdc++.h>
using namespace std;
int n, a[1001], m, b[1001], mem[1001][1001];
bool mark[1001][1001] = {0};
int LCS(int i, int j)
{
	if (i == 0 || j == 0) return mark[i][j] = 0;
	if (mark[i][j]) return mem[i][j];
	if (a[i] == b[j]) mem[i][j] = max(max(LCS(i - 1, j), LCS(i, j - 1)), LCS(i - 1, j - 1) + 1);  
	else mem[i][j] = max(LCS(i - 1, j), LCS(i, j - 1));
	mark[i][j] = 1;
	return mem[i][j];
}
void trace(int i, int j)
{
	if (i == 0 || j == 0) return;
	if (a[i] == b[j])
	{
		trace(i - 1, j - 1);
		cout << a[i] << " ";
		return;
	}
	if (mem[i][j] == mem[i][j - 1]) trace(i, j - 1);
	else trace(i - 1, j);
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	cin >> m;
	for (int i = 1; i <= m; i++) cin >> b[i];
	int maxlcs = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			maxlcs = max(maxlcs, LCS(i, j));
	cout << maxlcs << endl;
	trace(n, m);
	return 0;
}
