/*
    Rating : 1200
    画图 分成 00 01 11 10 四种情况进行分析 相乘就可以
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 2e5 + 10;
#define int long long
int cnt1, cnt2, cnt3, cnt4;
signed main()
{
    int n;
    string a, b;
    cin >> n;
    cin >> a >> b;
    for (int i = 0; i < n; i ++ )
    {
        if(a[i] == '0' && b[i] == '0')cnt3 ++;
        if(a[i] == '0' && b[i] == '1')cnt1 ++;
        if(a[i] == '1' && b[i] == '0')cnt4 ++;
        if(a[i] == '1' && b[i] == '1')cnt2 ++;
    }
    int ans = cnt3 * cnt2 + cnt3 * cnt4 + cnt4 * cnt1;
    cout << ans << endl;
    return 0;
}