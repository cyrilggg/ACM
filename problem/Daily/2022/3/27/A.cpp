#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int ans;
int m, n;
vector<int>col, row;
set<vector<pair<int,int>>>S;
void dfs(vector<pair<int,int>>v)
{
   bool check = true;
   for (int i = 0; i < m; i ++ )
   {
      for (int j = 0; j < n; j ++ )
      {
         bool checki = false, checkj = false;
         for (int k = 0; k < v.size(); k ++ )
         {
            if (v[k].first == col[i])
            {
               checki = true;
            }
            if (v[k].second == row[j])
            {
               checkj = true;
            }
         }
         check = check && checki && checkj;
      }
   }
   
    sort(v.begin(), v.end());
   if (check && !S.count(v))
   {
        S.insert(v);
        ans ++;
   }
   for (int i = 0; i < m; i ++ )
   {
      for (int j = 0; j < n; j ++ )
      {
         bool checkk = false;
         for (int k = 0; k < v.size(); k ++ )
         {
            if (v[k].first == col[i] && v[k].second == row[j]) checkk = true;
         }
         if (!checkk)
         {
            v.push_back({col[i], row[j]});
            dfs(v);
            v.pop_back();
         }
      }
   }
}

void solve()
{
   col.clear();
   row.clear();
   ans = 0;
   cin >> m >> n;
   for (int i = 1; i <= m; i ++ )
   {
      int x;
      cin >> x;
      col.push_back(x);
   }
   for (int i = 1; i <= n; i ++ )
   {
      int x;
      cin >> x;
      row.push_back(x);
   }
   vector<pair<int,int>>v;
   dfs(v);
   cout << ans << endl;
}

signed main()
{
   int t = 1;
   cin >> t;
   while (t -- )solve();
}