#include <bits/stdc++.h>
using namespace std;
#define int long long
const int  N = 2e5 + 10;
int a[N];
int n;
bool check()
{
    unordered_set<int>S;
    for (int i = 1; i <= n; i ++ )
    {
        if(S.count(a[i])) return false;
        S.insert(a[i]);
    }
    return true;
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= 2 * n; i ++ )  cin >> a[i];
    if (n == 2) {cout << "yes" << '\n'; return;}
    if (n == 3)
    {
        if (a[1] == a[4] && a[2] == a[5] && a[3] == a[6])
        {
            puts("no");
        }
        else puts("yes");
        return;
    }
    bool flag = 1;
    if (check())
    {
        if (a[n] != a[n + 1] && a[1] != a[2 * n]) flag = 0;
    }
    if (flag) puts("yes");
    else puts("no");
}

signed main()
{
   int t = 1;
   cin >> t;
   while (t -- )solve();
}