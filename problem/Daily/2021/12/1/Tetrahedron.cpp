/*
    Rating : 1500
    dp 题 从 顶点出发最后走回顶点的路线数，思路开始没推出来借鉴一下网上，可以构造两个dp，一个是走回到顶点的方案数f，一个是走到非顶点的方案数，则有
    f(i) = 3 * g(i - 1), g(i) = f(i - 1) + 2 * g(i)
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int mod = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    int f = 0, g = 1;
    for (int i = 2; i <= n; i ++ )
    {
        int tmp = f;
        f = (3 * g) % mod, g = (tmp + 2 * g) % mod;
    }
    cout << f << endl;
	return 0;
}