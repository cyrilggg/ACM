#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 10;
int idx;
vector<pair<int,int>> v, w;
int ans;

void add(int a, int b)
{
   v.push_back({a, b});
}

void query(int init)
{
   int cur = init;
   ans ++;
   bool flag = false;
   int cnt = 0;
   for (int i = 0; i < w.size(); i ++ )
   {
      if (!w[i].first) continue;
      if (w[i].first <= init)
      {
         w[i].first = 0;
         cnt += w[i].second;
         flag = true;
      }
      else
      {
         w[i].first -= init;
      }
   }
   init -= cnt;
   if (init <= 0 || !flag) return;
   else query(init);
}

signed main()
{
   int t = 1;
   cin >> t;
   while (t -- )
   {
      int op;
      cin >> op;
      if (op == 1)
      {
         int a, b;
         cin >> a >> b;
         add (a, b);
      }
      else
      {
         w = v;
         ans = 0;
         int init;
         cin >> init;
         query(init);
         cout << ans << endl;
      }
   }
}