/*
    Rating : 1500
    可以用字符串模拟，也可以直接算，可以注意到每次把原数字进位判断是否满足，大小即为进位所需的大小
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

long long sum(long long a)
{
	long long ans = 0;
	while(a > 0)
	{
		ans += a % 10;
		a /= 10;
	}
	return ans;
}

long long n, s;

int main() 
{
	int t;
	cin >> t;
	while (t -- )
	{
		cin >> n >> s;
		long long d = 10, buf = n;
		while(sum(n) > s)
		{
			n += d - n % d;
			d *= 10;
		}
		cout<< n - buf << endl;
	}
	return 0;
}