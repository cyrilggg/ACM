/*
    Rating : 1400
    一道bfs模板题，以前也写过，注意一下边界即可
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#define x first
#define y second
 
using namespace std;
const int N = 1e7 + 10;
bool vis[N];
int a, b;
 
int bfs()
{
    queue<pair<int,int>>q;
    q.push({a, 0});
    while(q.size())
    {
        auto t = q.front();
        q.pop();
        int x = t.x;
        int step = t.y;
        if(x == b)return step;
        if(vis[x])continue;
        vis[x] = true;
        if(!vis[x - 1] && x > 0) q.push({x - 1, step + 1});
        if(!vis[x * 2] && x < b) q.push({x * 2, step + 1});
    }
    return -1;
}
 
int main()
{
    cin >> a >> b;
    if(a > b) cout << a - b << endl;
    else
    cout << bfs() <<endl;
    return 0;
}