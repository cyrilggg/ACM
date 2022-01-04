/*
    昨晚自己写的时候有拆分过多种情况，但是没能保存原有的min和max 然后不知道怎么接着存下去，
    这里做的方法完全就是绕开了存的过程而是额外读取一整条长的
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int A = 1e9 + 1;
void solve()
{
    int n;
    cin >> n;
    int minL = A, costL = A;
    int maxR = 0, costR = A;
    int maxLen = 0, costLen = A;
    for (int i = 0; i < n; i++)
    {
        int l, r, c;
        cin >> l >> r >> c;
 
        if (l < minL)
            minL = l, costL = A;
        if (l == minL)
            costL = min(costL, c);
 
        if (maxR < r)
            maxR = r, costR = A;
        if (maxR == r)
            costR = min(costR, c);
 
        if (maxLen < r - l + 1)
            maxLen = r - l + 1, costLen = A;
        if (maxLen == r - l + 1)
            costLen = min(costLen, c);
 
        int ans = costL + costR;
        if (maxLen == maxR - minL + 1)
            ans = min(ans, costLen);
        cout << ans << "\n";
    }
}

int main()
{
    int t;
    cin >> t;
    while (t -- ) solve();
    return 0;
}