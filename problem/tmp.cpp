#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve()
{
    int n;
    string a;
    cin >> n >> a;
    int cnt = 0;
    vector<int>l, r;
    for (int i = 0; i < a.size(); i ++ )
    {
        if (a[i] == '(') l.push_back(i);
        else r.push_back(i);
    }
    int lidx = 0, ridx = 0;
    int i = 0;
    for (; i < a.size() - 1; )
    {

        if (a[i] == '(')
        {
            while (ridx < r.size() && r[ridx] <= i) ridx ++;
            while (lidx < l.size() && l[lidx] <= i) lidx ++;
            if (ridx == r.size() && lidx == l.size()) break;
            int maxn = -1;
            if (ridx < r.size()) maxn = max(r[ridx], maxn);
            if (lidx < l.size()) maxn = max(l[lidx], maxn);
            cnt ++ ;
            i = maxn + 1;
        }
        else
        {
            
         
            while (ridx < r.size() && r[ridx] <= i) ridx ++;
            if (ridx == r.size()) break;
            cnt ++ ;
            i = r[ridx] + 1;
            
        }
        cout << i <<' '<< lidx << ' ' <<ridx <<' '<<a.size()<<  endl;
    }
    cout << cnt << ' ' << a.size() - i << endl;
}

signed main()
{
   int t = 1;
   cin >> t;
   while (t -- )solve();
}