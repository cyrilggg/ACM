/*
    Rating : 1600
    思路： 要想获得最小的最大值，注意到最大值的判定方式： b[j] > a[j] for 0 < i < j || a[j] 是 b[j] 的前缀
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n, k;
    string a;
    cin >> n >> k >> a;
    sort(a.begin(), a.end());
    
    if (a[0] != a[k - 1])
    {
        cout << a[k - 1] << endl;
        return;
    }
    
    cout << a[0];
    if (a[k] != a[n - 1])
    {
        for (int i = k; i < n; i ++ )
            cout << a[i];
        cout << endl;
        return;
    }
    
    for (int i = 0; i < (n - 1) / k; i ++ )
        cout << a[n - 1]; 
    cout << endl;
        
}

signed main()
{
   int t = 1;
   cin >> t;
   while (t -- )solve();
}