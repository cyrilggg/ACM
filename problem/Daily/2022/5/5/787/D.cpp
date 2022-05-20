#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define returnNo return void(puts("No"))
#define returnYes return void(puts("Yes"))
const int N = 2e5 + 10;
vector<int>e[N];
map<int,int>mp;
vector<vector<int>>ans;
vector<int>cur;

void dfs(int root)
{
    if (e[root].size() == 0)
    {
        ans.push_back(cur);
        return;
    }
    for (int i = 0; i < e[root].size(); i ++ )
    {
        cur.push_back(e[root][i]);
        dfs(e[root][i]);
        cur.clear();        
    }
}

void solve()
{
    int n;
    cin >> n;
    mp.clear();
    cur.clear();
    ans.clear();
    for (int i = 1; i <= n; i ++ ) e[i].clear();
    int root = -1;
    for (int i = 1; i <= n; i ++ )
    {
        int x;
        cin >> x;
        if (x == i) root = i;
        else e[x].push_back(i);
    }
    
    cur.push_back(root);
    dfs(root);
    for (auto &an : ans)
    {
        cout << an.size() << endl;
        for (auto &ann : an)
        {
            cout << ann << ' ';
        }
        cout << endl;
    }
}

signed main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   int _ = 1;
   cin >> _;
   while (_--)
      solve();
}