#include <bits/stdc++.h>
using namespace std;
long long n;
vector <long long> a(100001, 0), l(100001, INT_MAX), pre(100001, 0), save;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	a[0] = INT_MIN;
	a[n + 1] = INT_MAX;
	l[0] = 0;
	long long ans = 0;
	for (int i = 1; i <= n; i++)
	{
    	long long res = lower_bound(l.begin(), l.end(), a[i]) - l.begin();
    	l[res] = a[i];
    	pre[i] = res;
    	ans = max(ans, res);
	}
	int i = n, exp = ans;
	for (int i = n; i >= 0; i--)
		if (pre[i] == exp)
		{
			save.push_back(i);
			exp--;
		}
	cout << ans << endl;
	for (int i = save.size() - 2; i >= 0; i--) cout << save[i] << " ";
	return 0;
}
