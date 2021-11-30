/*
    Rating : 1500
    �������ַ���ģ�⣬Ҳ����ֱ���㣬����ע�⵽ÿ�ΰ�ԭ���ֽ�λ�ж��Ƿ����㣬��С��Ϊ��λ����Ĵ�С
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