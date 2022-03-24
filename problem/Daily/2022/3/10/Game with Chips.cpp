/*
    注意到2 n m的步数挺大的， 所以只需要先让所有的个都回到 左上角，再像贪吃蛇一样跑完全图就行
*/
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second

constexpr int N = 210;
pair<int,int>s[N], e[N];
bool st[N];

int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	string ans;
	ans += string(n - 1, 'U') + string(m - 1, 'L');
	for (int i = 0; i < n; i ++ )
	{
	    ans += string(m - 1, "RL"[i % 2]);
	    if (i != n - 1)
	        ans += "D";
	}
	cout << ans.size() << endl;
	for (auto an : ans) cout << an;
	return 0;
}