/*
    Rating : 1600
    ��ԭ�����зֳ��������������У������Ŀ��������������
    1���������ϸ�����Ӷ��м������һ������ǰһ�εĶ�ĩ < ��һ�εĶ�ͷ - 1 ʱ���ı��м�����ֵ len1 + len2 + 1
    2�������������ӶΣ����ɸı�ǰһ�εĶ�ĩ���һ�εĶ��� len1 + len2
    3��ȡ��ӶΣ��޸�ǰһ������ֵ���һ������ֵ��len + 1
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