/*
    Rating : 1200
    根据题意一直模拟就可以了
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

bool check(int x)
{
    return x > 0;
}
const int N = 1e5 + 10;
int a[N];
int main() 
{
	int t;
	cin >> t;
	while (t -- ) 
	{
		int n;
		cin >> n;
		for (int i = 1;  i <= n; i ++ ) cin >> a[i];
		long long sum = 0;
		for (int i = 1; i <= n; ++i) {
			int cur = a[i];
			int j = i;
			while (j <= n && check(a[i]) == check(a[j])) 
			{
				cur = max(cur, a[j]);
				j ++ ;
			}
			sum += cur;
			i = j - 1;
		}
		cout << sum << endl;
	}
	
	return 0;
}