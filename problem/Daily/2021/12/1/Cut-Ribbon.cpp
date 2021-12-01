/*
    Rating : 1300
    ���԰�n����һ��������a,b,c������������Ʒ����������ֵΨһ����װ�����������������ǡ��װ�����⣬�ȳ�ʼ������Ϊ�����dp[0] = 0����
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 4010;
int dp[N];
int main()
{
    int n;
    cin >> n;
    memset(dp, -0x3f, sizeof dp);
    dp[0] = 0;
    for (int i = 1; i <= 3; i ++ )
    {
        int x;
        cin >> x;
        for (int j = x; j <= n; j ++ )
        {
            dp[j] = max(dp[j], dp[j - x] + 1);
        }
    }
    cout << dp[n] <<endl;
    return 0;
}