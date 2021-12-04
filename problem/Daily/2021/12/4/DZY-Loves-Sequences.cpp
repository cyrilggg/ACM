/*
    Rating : 1600
    将原序列切分出若干连续子序列，若更改可有如下三种情况
    1）当两个严格递增子段中间仅隔着一个数且前一段的段末 < 后一段的段头 - 1 时，改变中间数的值 len1 + len2 + 1
    2）连续的两个子段，若可改变前一段的段末或后一段的段首 len1 + len2
    3）取最长子段，修改前一个数的值或后一个数的值，len + 1
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int a[N];
struct Node
{
    int l;
    int r;
    int len;
}b[N];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++ )  cin >> a[i];
    int l = 1, tot = 0, ans = 0;
    for (int i = 2; i <= n; ++ i )
    {
        if (a[i] <= a[i - 1]) 
        {
            b[tot].l = l;
            b[tot].r = i - 1;
            b[tot].len = i - l;
            ans = max(ans, i - l);
            ++ tot;
            l = i;        
        }    
    }
    b[tot].l = l;
    b[tot].r = n;
    b[tot].len = n - l + 1;
    ans = max(ans,b[tot].len);
    if (tot)
    {
        ans += 1;
    }
    for (int i = 0; i < tot; i ++ )
    {
        if (a[b[i].r - 1] + 1 < a[b[i + 1]. l] || a[b[i].r] < a[b[i + 1]. l + 1] - 1)
        {
            ans = max(b[i].len + b[i + 1].len, ans);
        }
        
    }
    for (int i = 1; i < tot; i ++ )
    {
        if (b[i].len == 1)
        {
            if(a[b[i].r] + 1 < a[b[i + 1].l])
            {
                
                ans = max(b[i - 1].len + b[i + 1].len + 1, ans);
            }
        }
        
    }
    cout << ans <<endl;
    return 0;
}