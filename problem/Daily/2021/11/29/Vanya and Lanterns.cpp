/*
    Rating : 1200
    思维题，只需要排序一下 依次判断两个柱子间距离是否合适，注意一下边界就好
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
 
const int N = 1100;
double a[N];
double ans;
 
int main()
{
    int n, l;
    cin >> n >> l;
    for (int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
    }
    sort (a + 1, a + 1 + n);
    
    ans = a[1];
    for (int i = 1; i <= n - 1; i ++ )
    {
        if(a[i] + ans >= a[i + 1] - ans)continue;
        ans = max(ans, (a[i + 1] - a[i]) / 2);
    }
    ans = max(ans, l - a[n]);
    printf("%.10lf\n",ans);
    return 0;
}