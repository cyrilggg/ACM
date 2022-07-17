#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int maxn = 3005;

int main()
{
    int t(0);
    cin >> t;
    for (int k(1); k <= t; ++k)
    {
        string ss, tt;
        cin >> ss >> tt;
        i64 n = ss.length();
        int cnt(0);
        for (int i(0); i < n; ++i)
        {
            if (ss[i] == 'a' && tt[i] != 'a')
                cnt--;
            if (ss[i] != 'a' && tt[i] == 'a')
                cnt++;
        }
        string ans(n, 'a');
        int p = n - 1;
        cout << cnt << endl;
        while (cnt < 0)
        {
            if (ss[p] == 'a')
            {
                if (tt[p] == 'a')
                    --p;
                else if (cnt < -1)
                {
                    ans[p] = tt[p];
                    cnt += 2;
                    --p;
                }
                else if (tt[p] == 'b')
                {
                    ans[p] = 'c';
                    cnt++;
                    --p;
                }
                else
                {
                    ans[p] = 'b';
                    cnt++;
                    --p;
                }
            }
            else if (tt[p] != 'a' && ss[p] != tt[p])
            {
                ans[p] = tt[p];
                cnt++;
                --p;
            }
            else
            {
                --p;
            }
        }
        swap(ss, tt);
        cnt = -cnt;
        while (cnt < 0)
        {
            if (ss[p] == 'a')
            {
                if (tt[p] == 'a')
                    --p;
                else if (cnt < -1)
                {
                    ans[p] = tt[p];
                    cnt += 2;
                    --p;
                }
                else if (tt[p] == 'b')
                {
                    ans[p] = 'c';
                    cnt++;
                    --p;
                }
                else
                {
                    ans[p] = 'b';
                    cnt++;
                    --p;
                }
            }
            else if (tt[p] != 'a' && ss[p] != tt[p])
            {
                ans[p] = tt[p];
                cnt++;
                --p;
            }
            else
            {
                --p;
            }
        }
        cout << "Case " << k << ": " << ans << "\n";
    }
}