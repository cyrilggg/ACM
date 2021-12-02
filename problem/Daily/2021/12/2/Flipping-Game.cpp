/*
    Rating : 1200
    由于数据范围很小（只有100）因此有多种做法可以做
    1)暴力搜索，每次去找 i , j区间，每次在区间去数结果得出最大值，O(n^3)
    2)区间dp，对于每f[i][j]=max(f[i+1][j]+(a[i] xor 1 ) , f [i][j−1]+(a[j] xor 1)),O(n^2)(CSND思路)
    3)区间子序列最大和dp,预处理前缀和sum，如果选中区间内的数字，数字是1，造成-1的收益，数字是0，造成+1的收益，做出子序列最大和，O(n)
    （看了题解的hint弄出来的，如果数据范围开到1e5题目rating应该可以到1400)
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