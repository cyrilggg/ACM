#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1010;

void solve()
{
    int a, b;
    cin >> a >> b;
    if (a > b) swap (a, b);
    if (a + 1 == b)
    {
        puts("Yes");
        return;
    }
    else if (a == 1 && b == 10)
    {
        puts("Yes");
        return;
    }
    else puts("No");
}

signed main()
{
   int t = 1;
   //cin >> t;
   while (t -- )solve();
}