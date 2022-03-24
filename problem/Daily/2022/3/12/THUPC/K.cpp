#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define endl "\n"
#define eps 1e-12
#define pp pair<int, int>
#define sf scanf
#define pf printf
#define ms(a, b) memset(a, b, sizeof(a))
#define IOS std::ios_base::sync_with_stdio(0);

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int maxn = 1e3 + 10;
const int mod = 1e9 + 7;

int r, c;
string gra[maxn];
int gox[2] = {3, 2};
int goy[2] = {0, -2};
int num[maxn];
int now = 0;

struct node
{
    int x, y;
    int h;
};
/*
int bfs(int sx,int sy)
{
    pf("sx=%d sy=%d\n",sx,sy);
    queue <node> q;
    node st;
    st.x=sx,st.y=sy;
    st.h=0;
    q.push(st);
    int ret=1;
    while(!q.empty()){
        node p=q.front();
        q.pop();
        int x=p.x;
        int y=p.y;
        int h=p.h;
        ret=max(ret,h);
        pf("x=%d y=%d h=%d\n",x,y,h);
        for(int i=0;i<2;i++){
            int xx=x+gox[i];
            int yy=y+goy[i];
            if(gra[xx][yy]!='+'){
                continue;
            }
            node ps;
            ps.x=xx,ps.y=yy;
            if(i==0){
                ps.h=h+1;
            }else{
                ps.h=h;
            }
            q.push(ps);
        }
    }

    return ret;
}
*/

void dfs(int x, int y, int h)
{
    now = max(now, h);
    for (int i = 0; i < 2; i++)
    {
        int xx = x + gox[i];
        int yy = y + goy[i];
        if (gra[xx][yy] != '+')
        {
            return;
        }
        if (i == 0)
        {
            // pf("xx=%d yy=%d h=%d\n",xx,yy,h+1);
            dfs(xx, yy, h + 1);
        }
        else
        {
            // pf("xx=%d yy=%d h=%d\n",xx,yy,h);
            dfs(xx, yy, h);
        }
    }
    return;
}

int main()
{
    cin >> r >> c;
    getchar();
    for (int i = 1; i <= r; i++)
    {
        getline(cin, gra[i]);
        gra[i] = "x" + gra[i];
    }

    
    int cnt = 0;
    for (int i = 1; i <= r - 3; i++)
    {
        for (int j = 1; j <= c - 4; j += 2)
        {
            if (gra[i][j] == '+')
            {
                if (gra[i][j + 4] == '+')
                {
                    if (gra[i + 2][j + 4 - 2] == '+')
                    {
                        now = 0;
                       // pf("%d %d\n", i + 2, j + 4 - 2);
                        // num[++cnt]=bfs(i+2,j+4-2);
                        dfs(i + 2, j + 4 - 2, 0);
                        num[++cnt] = now;
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= cnt; i++)
    {
       // pf("num[%d]=%d\n", i, num[i]);
        ans += num[i];
    }
    pf("%d\n", ans);

    return 0;
}
