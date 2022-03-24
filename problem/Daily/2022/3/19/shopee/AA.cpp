#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n, sum, ans;
int a[25];


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i ++ )  cin >> a[i];
    unordered_map<int,vector<int>>cur;

    for (int i = 1; i < (1 << n); i ++ )
    {
        int cnt = 0;
        for (int j = 0; j < n; j ++ )
        {
            if ((i >> j) & 1)
                cnt += a[j + 1];
        }
        cur[cnt].push_back(i);
    }
    for (auto &[c, d] : cur)
    {
        //cout << c << endl;
        if (d.size() == 1) continue;
        
        for (int i = 0; i < d.size(); i ++ )
        {
            //cout << d[i] << ' ';
            for (int j = i + 1; j < d.size(); j ++ )
            {
                if ((d[i] & d[j]) == 0)
                {
                    ans = max(c, ans);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}