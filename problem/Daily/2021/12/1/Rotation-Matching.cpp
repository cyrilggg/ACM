/*
    Rating : 1400
    两个数组，可以通过向左或向右移动x位来使得两个数组匹配位最多
    暴力做法可以O(n^2)，由于题目保证同一个数组没有重复的数字，我们可以开两个map来存储，其中 第一个用来存第一个数组每个数字的位置
    这样一来使用第二个数组时可以通过查询该位在a数组的位置得到距离，用第二个map存储该距离下可以匹配最多的数，取最大值就好
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