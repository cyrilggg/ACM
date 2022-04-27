#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, l;
struct Node
{
    int x, y, z;
    int ans, idx;
}s[N];
bool cmp(Node a, Node b)
{
    return atan2(a.x, a.y) > atan2(b.x, b.y);
}
bool cmp2(Node a, Node b)
{
    return a.idx < b.idx;
}
int main()
{
    cin >> n >> l;
    for (int i = 1; i <= n; i ++ )
    {
        cin >> s[i].x >> s[i].y >> s[i].z;
        int a = s[i].x, b = s[i].y;
        s[i].y = -a, s[i].x = b;
        s[i].idx = i;
        s[i].ans = -1;
    }
    int cur = 0;
    bool flag = false;
    bool find = false;
    sort(s + 1, s + 1 + n, cmp);
    double now = 0x3f3f3f3f3f;
    int last = -1;
    for (int i = 1; i <= 5; i ++ )
        for (int j = 1; j <= n; j ++ )
        {
            if (s[i].ans != -1) continue;
            if (fabs(atan2(s[j].x, s[j].y) - now) < 1e-6)
            {
                if (l >= sqrt(s[j].x * s[j].x + s[j].y * s[j].y))
                {
                    if (flag) l += s[j].z;
                    else l -= s[j].z;
                    s[j].ans = s[last].ans; 
                    cur ++;
                }
            }
            else{
                flag = 1 - flag;
                now = atan2(s[j].x, s[j].y);
                if (l >= sqrt(s[j].x * s[j].x + s[j].y * s[j].y))
                {
                    if (flag) l += s[j].z;
                    else l -= s[j].z;
                    s[j].ans = cur; 
                    last = j;
                    cur ++;
                }
            }
        }
    sort(s + 1, s + 1 + n, cmp2);
    for (int i = 1; i <= n; i ++ ) cout << s[i].ans << " \n"[i == n];
    return 0;
}