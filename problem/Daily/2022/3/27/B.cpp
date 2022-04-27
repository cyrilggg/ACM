#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int a[4];
bool st[4];
int ans = 0;
set<int>S;

int cal(vector<int>v, vector<int>move)//计算结果
{
    vector<int>res,mo, re, m;
    for (int i = 0; i < move.size(); i ++ ) // 查连
    {
        int cnt = v[i];
        while (i < move.size() && move[i] == 3 )
        {
            cnt = 10 * cnt + v[i + 1];
            i ++;
        }
        res.push_back(cnt);
        if (i == move.size() - 1 && move[i] != 3) res.push_back(v[i + 1]);
        if(i < move.size())mo.push_back(move[i]);
    }

    for (int i = 0; i < mo.size(); i ++ ) // x
    {
        int cnt = res[i];
        while (i < mo.size() && mo[i] == 2)
        {
            cnt *= res[i + 1];
            i ++;
        }
        re.push_back(cnt);
        
        if (i == mo.size() - 1 && mo[i] != 2) re.push_back(res[i + 1]);
        if(i < mo.size())m.push_back(mo[i]);
    }

    int cur = re[0];
    for (int i = 0; i < m.size(); i ++ )
    {
        if (m[i] == 1)
        {
            cur += re[i + 1];
        }
        else cur -= re[i + 1];
    }
    // if(cur == 6)
    // {
    // for (auto vv : v)
    //     cout << vv << ' ';
    // cout << endl;

    // for (auto mm : move)
    //     cout << mm << ' ';
    // cout << endl;

    // cout << cur << endl;
    // }
    return cur;
}

void dfs(vector<int>v, vector<int>move, int flag)//flag表示有没有用过除 连号 之外的运算符
{
    if (v.size() == 4){
        if (flag && !S.count(cal(v, move)))
        {
            if (cal(v, move) >= 0)
            {
                S.insert(cal(v, move));
                ans ++;
            }
        }
        return;
    }

    for (int i = 0 ; i < 4; i ++ ){
        if (st[i]) continue;
        v.push_back(a[i]);
        st[i] = 1;
        if (v.size() < 4)
        {
            for (int j = 0; j < 4; j ++ )
            {
                move.push_back(j);
                if (j != 3) dfs(v, move, 1);
                else dfs(v, move, flag);
                move.pop_back();
            }
        }
        else dfs(v, move, flag);
        st[i] = 0;
        v.pop_back();
    }
}

void solve()
{
   for (int i = 0; i < 4; i ++ ){
       cin >> a[i];
   }

   vector<int>v, m;

   dfs(v, m, 0);
   
//    for (auto s : S)
//         cout << s << endl;
   
   cout << ans << endl;
}

signed main()
{
   int t = 1;
   //cin >> t;
   while (t -- )solve();
}