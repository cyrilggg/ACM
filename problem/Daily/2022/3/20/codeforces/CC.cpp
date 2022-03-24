#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int a[N];
int n, sum;
bool cmp(int x, int y)
{
    return x > y;
}
void solve()
{
    cin >> n;
    sum = 0;
    priority_queue<int>q;
    for (int i = 1; i <= n; i ++ ) 
    {
        cin >> a[i];
        sum += a[i];
    }
    int k = n;
    int s = 1;
    if (n == 1)puts("YES");
    else
    {
        sort (a + 1, a + 1 + n, cmp);
        bool flag = 1;
        q.push(sum);
        while (q.size())
        {
            auto tmp = q.top();
            q.pop();
            if (tmp == a[s])
            {
                k --;
                s ++;
                continue;
            }
            if (tmp > 1)
            {
                int fi = tmp / 2;
                int sec = tmp - fi;
                q.push(fi);
                q.push(sec);
            }
            if (q.size() == k)
            {
                auto qq = q;
                int idx = s;
                while (qq.size())
                {
                    //cout << qq.top() << ' '<< a[idx] << endl;
                    if( qq.top() != a[idx ++ ]) flag = 0;
                    qq.pop();
                }
                break;
            }
        }
        if (flag) puts("YES");
        else puts("NO");
    }
}

signed main()
{
   int t = 1;
   cin >> t;
   while (t -- )solve();
}
