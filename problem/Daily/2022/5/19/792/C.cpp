#include <bits/stdc++.h>
using namespace std;
#define int long long
//#define endl '\n'
#define returnNo return void(puts("No"))
#define returnYes return void(puts("Yes"))

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '['; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << ']'; }
 
void debug_out() { cerr << endl; }
template<typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << ' ' << H; debug_out(T...); }
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 
#endif

void solve()
{
    int n, m;
    cin >> n >> m;
    map<pair<int,int>, int>rank;
    vector<vector<int>>v(n + 1, vector<int>(m + 1));
    vector<vector<pair<int,int>>> tmp(n + 1, vector<pair<int,int>>(m + 1));
    for (int i = 1; i <= n; i ++ )
    {
        for (int j = 1; j <= m; j ++ )
        {
            cin >> v[i][j];
            tmp[i][j].first = v[i][j];
            tmp[i][j].second = j;
        }
    }
    for (int i = 1; i <= n; i ++ )
    {
        sort(tmp[i].begin() + 1, tmp[i].end());
        for (int j = 1; j <= m; j ++ )
        {
            rank[{i, tmp[i][j].second}] = j;
        }
    }

    vector<pair<int,int>>ans;
    vector<pair<int,int>>q;
    bool flag = true;

    for (int j = 1; j <= m; j ++ )
    {
        int st = rank[{1, j}];
        for (int i = 2; i <= n; i ++ )
        {
            if (rank[{i, j}] != st && tmp[i][st].first != v[i][j])
            {
                if (tmp[1][rank[{i, j}]].first != v[1][j])
                {
                    flag = false;
                    debug(i, j, rank[{i, j}], st, tmp[i][st].first, v[i][j]);
                }
                else
                {
                    st = rank[{i, j}];
                }
            }
        }
        if (j != st)q.push_back({j, st});
    }
    debug(q);
    //高度和位置
    if (flag)
    {
        if (q.empty())
        {
            cout << 1 << ' ' << 1 << endl;
        }
        else
        {
            map<pair<int,int>,int>used;
            for (int i = 0; i < q.size(); i ++ )
            {
                debug(q);
                int minx = 1e12, mini = i;
                for (int j = i + 1; j < q.size() - 1; j ++ )
                {
                    if (q[j].second <= minx)
                    {
                        minx = q[j].second;
                        mini = j;                 
                    }
                }
                swap(q[mini], q[i]);
                if (mini != i)
                    ans.push_back({mini, i});
            }
            debug(ans);
            if (ans.size() > 1)
            {
                cout << -1 << endl;
                return;
            }
            for (auto an : ans)
            {
                cout << an.first << ' ' << an.second << endl;
            }
        }
    }
    else cout << -1 << endl;
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