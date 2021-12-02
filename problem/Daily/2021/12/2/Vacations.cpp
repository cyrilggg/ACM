/*
    Rating : 1400
    因为可以看成是 休息 工作一 工作二 三个状态的转化，想到昨天的四面体以及状态机模型dp，分析好状态变化过程画个图就好了
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 110;
int a[N], n;
int dp[N][3];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++ )  cin >> a[i];
    int maxx = -1;
    
    for (int i = 1; i <= n; i ++ )
    {
        dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2]));
        if (a[i] == 1 || a[i] == 3) dp[i][1] = max(dp[i - 1][2] + 1,dp[i - 1][0] + 1);
        if (a[i] == 2 || a[i] == 3) dp[i][2] = max(dp[i - 1][1] + 1,dp[i - 1][0] + 1);
        maxx = max(max(maxx, dp[i][0]), max(dp[i][1], dp[i][2]));
    }
    cout << n - maxx << endl;
    return 0;
}