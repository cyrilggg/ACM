/*
    Rating : 1600
    思路 ： 找破坏环的最合适的位置，取最小值
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N = 3e5 + 10;
signed main()
{
    ios :: sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t -- )
    {
        int n;
        cin >> n;
        int ans = 0;
        vector<int> A (n + 1), B (n + 1), C(n + 1);
        for (int i = 1; i <= n; i ++ )
        {
            cin >> A[i] >> B[i];
        }
        for (int i = 1; i <= n; i ++ )
        {
            if (i == 1)
                C[1] = max(0ll, A[1] - B[n]);
            else
            {
                C[i] = max(0ll, A[i] - B[i - 1]);
            }
            ans += C[i];
        }
        int minn = 1e18;
        for (int i = 1; i <= n; i ++ )
        {
            minn = min(minn, ans - C[i] + A[i]);
        }
        cout << minn << endl;
    }
    return 0;
}