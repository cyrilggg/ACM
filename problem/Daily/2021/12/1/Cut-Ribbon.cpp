/*
    Rating : 1300
    可以把n当成一个背包，a,b,c当成是三种物品的重量，价值唯一，求装满的最多容量，对于恰好装满问题，先初始化数组为负无穷，dp[0] = 0即可
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 4010;
int dp[N];
int main()
{
    int n;
    cin >> n;
    memset(dp, -0x3f, sizeof dp);
    dp[0] = 0;
    for (int i = 1; i <= 3; i ++ )
    {
        int x;
        cin >> x;
        for (int j = x; j <= n; j ++ )
        {
            dp[j] = max(dp[j], dp[j - x] + 1);
        }
    }
    cout << dp[n] <<endl;
    return 0;
}