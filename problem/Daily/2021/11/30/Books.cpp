/*
    Rating : 1400
    用两个指针表示取的范围,答案每次就是从 j - i取最大值，复杂度为O(n)
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1e5 + 10;
int a[N];

signed main()
{
    int n, m;
    cin >> n >> m;
    
    for (int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
    }
    int ans = -1;
    int sum = 0;
    for (int i = 1, j = 1; j <= n && i <= n; i ++ )
    {
        j = max(i, j);
        sum = max(sum - a[i - 1], 0);
        while(sum + a[j] <= m && j <= n)
        {
            sum += a[j];
            j ++;
        }
        ans = max(ans, j - i);
    }
    cout << ans << endl;
    return 0;
}