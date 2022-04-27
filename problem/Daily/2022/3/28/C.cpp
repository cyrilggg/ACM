#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve()
{
    int n;
    cin >> n;
    vector<int>c(n);
    
    for (int i = 0; i < n; i ++ )  cin >> c[i];
    auto it = find(c.begin(), c.end(), 1);
    
    if (it == c.end())
    {
        cout << "NO" << endl;
        return;
    }
    rotate(c.begin(), it, c.end());
    for (int i = 1; i < n; i ++ )
    {
        if (c[i] > c[i - 1] + 1 || c[i] == 1 )
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

signed main()
{
   int _ = 1;
   cin >> _;
   while (_ -- )solve();
}