/*
    Rating : 1200
    ˼ά�⣬ֻ��Ҫ����һ�� �����ж��������Ӽ�����Ƿ���ʣ�ע��һ�±߽�ͺ�
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
 
const int N = 1100;
double a[N];
double ans;
 
int main()
{
    int n, l;
    cin >> n >> l;
    for (int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
    }
    sort (a + 1, a + 1 + n);
    
    ans = a[1];
    for (int i = 1; i <= n - 1; i ++ )
    {
        if(a[i] + ans >= a[i + 1] - ans)continue;
        ans = max(ans, (a[i + 1] - a[i]) / 2);
    }
    ans = max(ans, l - a[n]);
    printf("%.10lf\n",ans);
    return 0;
}