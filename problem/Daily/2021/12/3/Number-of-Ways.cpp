/*
    Rating : 1700
    思路过程：题目想要询问所有构造三段等于 sum[n] / 3 的排列方式(sum[n]是总和)
    最早可以想到的是只要确定了中间数组的摆法，就可以得到答案
    当时的思路是记录前缀和，用哈希表存储前缀和等于 sum / 3的位置 （即第一段的末尾再从末尾出发，重新遍历到后即可得出答案）
    但这样的做法是O(n^2)的结果，多次尝试推导出数学公式，无果，看tutorial.
    答案的思路其实大体相同，不同的是在后半的时候，会重新在后往前遍历，当成一个差分数组来找第三段的开头，用cnt[]作为后缀和
    因此再从头往后走时，若到了sum / 3的位置 ， 直接加上cnt[i + 2]（ i 满足第一段的末尾 , i 表示至少要放一个，i + 2 是第三段的开头方法
    依次累加就可以了
    因此修改自己代码的时候可以继续存好哈希表，一次次加 i + 2就好
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
    
    if(mp.count(s[n] / 3) && s[n] / 3 * 3 == s[n])//判断有可整除
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