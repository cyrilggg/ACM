#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m;

int get(int i)
{
    return ((m % i != 0) ? (i - m % i) : 0)  + n - i;
}

int check(int l, int r)
{
    int x = get(l), y = get(r); 
    return x - y;
}

void solve()
{
    cin >> n >> m;
    if (m % n == 0) puts("0");
    else
    {
        int ans = 1e12;
        if (n > m) ans = n - m % (m + 1);
        else
        {
            int l = 1, r = n;
            while(l < r)  // 三分x
            {
                int mid = (l + r) / 2;
                int mmid = (mid + r) / 2;
                if(check(l, mid) * check(mid, mmid) < 0) r = mmid;
                else l = mid; // 这里是r = mmid;
                cout << l <<' ' <<r << endl;
            }
            ans = get(l);
        }
        cout << ans << endl;
    }
}

signed main()
{
   int t = 1;
   cin >> t;
   while (t -- )solve();
}