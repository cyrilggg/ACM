/*
    Rating: 1600
    思路：构造方法 12 10 8 6 (2 4) 1 3 5 7 9...
    特别放置一下 2 4即可
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1010;
int n;

void solve()
{
    cin >> n;
    if (n < 4) puts("-1");
    else
    {
        for (int i = n - (n & 1); i > 4; i -= 2)
        {
            cout << i << ' ';
        }
        cout << 2 << ' ' << 4 << ' ';
        
        for (int i = 1; i <= n; i += 2)
        {
            cout << i << ' ';
        }
        cout << endl;
    }
}

signed main()
{
   int t = 1;
   cin >> t;
   while (t -- )solve();
}