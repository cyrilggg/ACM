/*
    Rating : 1200
    �������ݷ�Χ��С��ֻ��100������ж�������������
    1)����������ÿ��ȥ�� i , j���䣬ÿ��������ȥ������ó����ֵ��O(n^3)
    2)����dp������ÿf[i][j]=max(f[i+1][j]+(a[i] xor 1 ) , f [i][j�6�11]+(a[j] xor 1)),O(n^2)(CSND˼·)
    3)��������������dp,Ԥ����ǰ׺��sum�����ѡ�������ڵ����֣�������1�����-1�����棬������0�����+1�����棬�������������ͣ�O(n)
    ����������hintŪ�����ģ�������ݷ�Χ����1e5��ĿratingӦ�ÿ��Ե�1400)
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 110;
int dp[N], sum[N], w[N];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++ )  
    {
        int x;
        cin >> x;
        sum[i] = sum[i - 1] + x;
        if(x == 0) w[i] = 1;
        else w[i] = -1;
    }
    
    int res = -0x3f3f3f3f, l, r;
    for (int i = 1, f = -1, start; i <= n; i ++ )
    {
        if (f < 0) f = 0, start = i;
        f += w[i];
        if (res < f)
        {
            res = f;
            l = start, r = i;
        }
    }
    
    cout << res + sum[n] << endl;


    return 0;
}