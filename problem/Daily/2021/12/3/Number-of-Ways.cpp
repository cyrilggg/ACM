/*
    Rating : 1700
    ˼·���̣���Ŀ��Ҫѯ�����й������ε��� sum[n] / 3 �����з�ʽ(sum[n]���ܺ�)
    ��������뵽����ֻҪȷ�����м�����İڷ����Ϳ��Եõ���
    ��ʱ��˼·�Ǽ�¼ǰ׺�ͣ��ù�ϣ��洢ǰ׺�͵��� sum / 3��λ�� ������һ�ε�ĩβ�ٴ�ĩβ���������±������󼴿ɵó��𰸣�
    ��������������O(n^2)�Ľ������γ����Ƶ�����ѧ��ʽ���޹�����tutorial.
    �𰸵�˼·��ʵ������ͬ����ͬ�����ں���ʱ�򣬻������ں���ǰ����������һ������������ҵ����εĿ�ͷ����cnt[]��Ϊ��׺��
    ����ٴ�ͷ������ʱ��������sum / 3��λ�� �� ֱ�Ӽ���cnt[i + 2]�� i �����һ�ε�ĩβ , i ��ʾ����Ҫ��һ����i + 2 �ǵ����εĿ�ͷ����
    �����ۼӾͿ�����
    ����޸��Լ������ʱ����Լ�����ù�ϣ��һ�δμ� i + 2�ͺ�
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#define int long long
using namespace std;
const int N = 5e5 + 10;
int a[N], s[N], ans;
int cnt[N];
unordered_map<int,vector<int>>mp;
signed main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
    }
    
    for (int i = 1; i <= n; i ++ )
    {
        s[i] = s[i - 1] + a[i];
        if(i < n - 1) mp[s[i]].push_back(i);
    }
    
    for (int i = n; i; i -- )
    {
        if(s[n] - s[i - 1] == s[n] / 3)
        {
            cnt[i] = 1;
        }
    }
    
    for (int i = n - 1; i; i -- )
    {
        cnt[i] += cnt[i + 1];
    }
    
    if(mp.count(s[n] / 3) && s[n] / 3 * 3 == s[n])//�ж��п�����
    {
        for (int i = 0; i < mp[s[n] / 3].size(); i ++ )
        {
            ans += cnt[mp[s[n] / 3][i] + 2];
            
        }
        cout << ans << endl;
    }
    else cout << 0 << endl;
    return 0;
}