/*
    rating : 1700
    看着就想到最长上升子序列，结果数据范围过不去，换成nlogn的发现没法套。。最后看题解才发现很聪明
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;
const int N = 2e5 + 10;
int a[N];
int main() 
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	
	map<int, int> dp;
	
	int ans = 0;
	int lst = 0;
	for (int i = 0; i < n; ++i) {
		int x = a[i];
		dp[x] = dp[x - 1] + 1;
		if (ans < dp[x]) {
			ans = dp[x];
			lst = x;
		}
	}
	
	vector<int> res;
	for (int i = n - 1; i >= 0; --i) {
		if (a[i] == lst) {
			res.push_back(i);
			--lst;
		}
	}
	reverse(res.begin(), res.end());
	
	printf("%d\n", ans);
	for (auto it : res)
		printf("%d ", it + 1);
	puts("");
	
	return 0;
}