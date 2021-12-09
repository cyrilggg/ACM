/*
    Rating : 1500
    感觉最近做了很多状态机模型dp，一看就可以想到分成看左和砍右两种情况就可以了，刚刚回看感觉甚至可以滚动优化
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define int long long
const int N = 1e5 + 10;
pair<int,int>a[N];
int dp[N][2];
signed main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++ )  cin >> a[i].first >> a[i].second;
    dp[1][0] = 1;
    if (a[1].second + a[1].first <= a[2].first) dp[1][1] = 1;
    a[n + 1].first = 1e12;
    for (int i = 2; i <= n; i ++ )
    {
        dp[i][0] = max(dp[i - 1][0] + (a[i].first - a[i].second > a[i - 1].first), dp[i - 1][1] + (a[i].first - a[i].second > a[i - 1].first + a[i - 1].second)); 
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + (a[i].first + a[i].second < a[i + 1].first);
    }
    cout << max(dp[n][0], dp[n][1]) << endl;
    return 0;
}