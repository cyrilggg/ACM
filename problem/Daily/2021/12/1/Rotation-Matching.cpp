/*
    Rating : 1400
    �������飬����ͨ������������ƶ�xλ��ʹ����������ƥ��λ���
    ������������O(n^2)��������Ŀ��֤ͬһ������û���ظ������֣����ǿ��Կ�����map���洢������ ��һ���������һ������ÿ�����ֵ�λ��
    ����һ��ʹ�õڶ�������ʱ����ͨ����ѯ��λ��a�����λ�õõ����룬�õڶ���map�洢�þ����¿���ƥ����������ȡ���ֵ�ͺ�
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>

using namespace std;
const int N = 2e5 + 10;
unordered_map<int,int>mp, mpc;

int main()
{
    int n;
    cin >> n;
    int ans = -1;
    
    for (int i = 1; i <= n; i ++ )
    {
        int x;
        cin >> x;
        mp[x] = i;
    }
    for (int i = 1; i <= n; i ++ )
    {
        int x;
        cin >> x;
        int diff = mp[x] - i;
        if (diff < 0) diff += n;
        mpc[diff]++;
        ans = max(ans, mpc[diff]);
    }
    cout << ans << endl;
    return 0;
}