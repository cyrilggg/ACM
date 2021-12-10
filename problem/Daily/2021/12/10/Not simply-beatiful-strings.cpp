/*
    Rating : 1400
    直接拆分情况 等于4的肯定行 大于4的肯定不行 等于3的 如果就是abc 即长度是3就不行 等于2的 种数不能都是1 等于1肯定不行
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool check(string a)
{
    unordered_map<char,int>s;
    for (int i = 0; i < a.size(); i ++ )
    {
        s[a[i]] ++;
    }
    if (s.size() > 4) return false;
    if (s.size() <= 1) return false;
    if (s.size() == 2)
    {
        for (auto &[c, d] : s)
        {
            if(d == 1)return false;
        }
    }
    if (s.size() == 3)
    {
        if(a.size() == 3)return false;
    }
    return true;
}
signed main()
{
    string a;
    cin >> a;
    if (check(a))puts("Yes");
    else puts("No");
    return 0;
}
