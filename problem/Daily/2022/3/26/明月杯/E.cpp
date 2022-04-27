#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int ans;

bool che(pair<int,int>a, pair<int,int>b, pair<int,int>c)
{
    return ((c.second - a.second) * (b.first - a.first) - (b.second - a.second) * (c.first - a.first)) > 0;
}
bool check(vector<pair<int,int>>v, pair<int,int>p)
{
    if (count(v.begin(), v.end(), p)) return false;
    if (v[v.size() - 1].first - p.first == 2 && v[v.size() - 1].second - p.second != 1) return false;
    if (v[v.size() - 1].second - p.second == 2 && v[v.size() - 1].first - p.first != 1) return false;
    
    if (v.size() == 3)
    {
        //if (v[2].second - v[1].second == v[1].second - v[0].second && v[2].first - v[1].first == v[1].first - v[0].first)return true; //三点共线
        if (che(v[0], v[1], v[2]) * che(v[0], v[1], p) >= 0) return true; 
        else if (v[0].first == 1 && v[0].second == 1 && v[1].first == 2 && v[1].second == 2 && ((v[3].first == 2 && v[3].second == 3 && p.first == 3 && p.second == 2) || (v[3].first == 3 && v[3].second == 2 && p.first == 2 && p.second == 3))) return true;
        else if (v[0].first == 3 && v[0].second == 1 && v[1].first == 2 && v[1].second == 2 && ((v[3].first == 1 && v[3].second == 2 && p.first == 2 && p.second == 1) || (v[3].first == 2 && v[3].second == 1 && p.first == 1 && p.second == 2))) return true;
        else if (v[0].first == 1 && v[0].second == 3 && v[1].first == 2 && v[1].second == 2 && ((v[3].first == 2 && v[3].second == 1 && p.first == 3 && p.second == 2) || (v[3].first == 3 && v[3].second == 2 && p.first == 2 && p.second == 1))) return true;
        else if (v[0].first == 3 && v[0].second == 3 && v[1].first == 2 && v[1].second == 2 && ((v[3].first == 1 && v[3].second == 2 && p.first == 2 && p.second == 1) || (v[3].first == 2 && v[3].second == 1 && p.first == 1 && p.second == 2))) return true;
        else return false;
    }

    return true;
}

void dfs(vector<pair<int,int>>v, int x)
{
    if (x == 4)
    {
        ans ++;
        return;
    }
    for (int i = 1; i <= 3; i ++ )
        for (int j = 1; j <= 3; j ++ )
        {
            if (check(v, {i, j}))
            {
                v.push_back({i, j});
                dfs(v, x + 1);
                v.pop_back();
            }
        }
}
void solve()
{
    vector<pair<int,int>>v;
    for (int i = 1; i <= 3; i ++ )
        for (int j = 1; j <= 3; j ++ )
        {
            v.clear();
            v.push_back({i, j});
            dfs(v, 1);
        }
    cout << ans / 2 << endl;
}

signed main()
{
   int t = 1;
   //cin >> t;
   while (t -- )solve();
}