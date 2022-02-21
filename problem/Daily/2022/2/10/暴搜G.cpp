#include <bits/stdc++.h>
using namespace std;
int a[13];
int ans;
map<string,int>mp;
void dfs(int x)
{
    if (x == 6)
    {
        string s;
        for (int i = 0; i < 13; i ++ )
        {
            s = s + to_string(a[i]);
        }
        if (mp.count(s))return;
        mp[s] = 1;
        ans ++;
        return;
    }
    
    for (int i = 0; i < 13; i ++ )
    {
        if (a[i])
        {
            a[i] --;
            x ++;
            dfs(x);
            x --;
            a[i] ++;
        }
    }
}

int main()
{
    for (int i = 0; i < 13; i ++ ) a[i] = 4;
    dfs(0);
    cout << ans << endl;
    return 0;
}