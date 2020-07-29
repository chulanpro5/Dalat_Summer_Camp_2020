#include <bits/stdc++.h>
using namespace std;

int f[1001][1001], n, m, type[1001][1001];
bool mark[1001][1001] = {0};
string a, b;
vector <pair<int, int>> res;

int LCS(int i, int j)
{
	if (i == 0) 
	{
		f[i][j] = j;
		type[i][j] = 3;
		return f[i][j];
	}
	if (j == 0)
	{
		f[i][j] = i;
		type[i][j] = 2;
		return f[i][j];
	}
	if (mark[i][j]) return f[i][j];
	if (a[i] == b[j]) f[i][j] = min(f[i][j], LCS(i - 1, j - 1));
	else 
	{
		if (f[i][j] > LCS(i - 1, j - 1) + 1)
		{
			f[i][j] = LCS(i - 1, j - 1) + 1;
			type[i][j] = 1;
		}
	}
	if (f[i][j] > LCS(i - 1, j) + 1)
	{
		f[i][j] = LCS(i - 1, j) + 1;
		type[i][j] = 2;
	}
	if (f[i][j] > LCS(i, j - 1) + 1)
	{
		f[i][j] = LCS(i, j - 1) + 1;
		type[i][j] = 3;
	}
	mark[i][j] = 1;
	return f[i][j];
}

void trace(int i, int j)
{
	if (i == 0 && j == 0) return;
	if (type[i][j] == 0)
	{
		trace(i - 1, j - 1);
	}
	if (type[i][j] == 1) 
	{
		cout << "REPLACE " << i << " " << b[j] << endl;
		trace(i - 1, j - 1);
	}
	if (type[i][j] == 2)
	{
		cout << "DELETE " << i << endl;
		trace(i - 1, j);
	}
	if (type[i][j] == 3)
	{
		cout << "INSERT " << i + 1 << " " << b[j] << endl;
		trace(i, j - 1);
	}
}

int main()
{
	cin >> a >> b;
	n = a.size(); m = b.size();
	a = ' ' + a;
	b = ' ' + b;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			f[i][j] = INT_MAX;
	cout << LCS(n, m) << endl;
	trace(n, m);
	return 0;
}
