#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define int long long

typedef unsigned long long ULL;
const int N = 5e6 + 10, P = 131;

ULL h1[N], h2[N], p[N];

ULL get(int l,int r)
{
    return h1[r] - h1[l-1] * p[r-l+1];
}

ULL getre(int l,int r)
{
    return h2[r] - h2[l-1] * p[r-l+1];
}

void solve()
{
    string a;
    cin >> a;
    string b = a;
    reverse(b.begin(), b.end());
    vector<int>ans;

    int n = a.size();
    a = "x" + a;
    b = "x" + b;
    p[0] = 1;
    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }
    for (int i = 1; i <= n; i ++ )
    {
        p[i] = p[i - 1] * P;
        h1[i] = h1[i - 1] * P + a[i];
        h2[i] = h2[i - 1] * P + b[i];
    }

    for (int i = 2; i <= n; i ++ )
    {
        int j = i;
        bool flag = true;
        while (j <= n)
        {
            if (j * 2 <= n)
            {
                if (get(1, j - 1) == getre(n - (2 * j - 1) + 1, n - (j + 1) + 1))
                {
                    j += j - 1;
                }
                else
                {
                    flag = false;
                    break;
                }
            }
            else
            {
                if (get(j - n + j, j - 1) != getre(1, n - j))
                {
                    flag = false;
                    break;
                }
                break;
            }

        }
        if (flag) ans.push_back(i);
    }
    for (auto an : ans) cout << an << ' ';
    cout << endl;
}

signed main()
{
    int t = 1;
    cin >> t;
    while (t -- )
        solve();
}