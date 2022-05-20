#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define returnNo return void(puts("No"))
#define returnYes return void(puts("Yes"))

string tran(string s) //把十六进制改成二进制字符串
{
    string ans = "";
    for (auto &ss : s)
    {
        if (ss == '0')
            ans += "0000";
        if (ss == '1')
            ans += "0001";
        if (ss == '2')
            ans += "0010";
        if (ss == '3')
            ans += "0011";
        if (ss == '4')
            ans += "0100";
        if (ss == '5')
            ans += "0101";
        if (ss == '6')
            ans += "0110";
        if (ss == '7')
            ans += "0111";
        if (ss == '8')
            ans += "1000";
        if (ss == '9')
            ans += "1001";
        if (ss == 'A')
            ans += "1010";
        if (ss == 'B')
            ans += "1011";
        if (ss == 'C')
            ans += "1100";
        if (ss == 'D')
            ans += "1101";
        if (ss == 'E')
            ans += "1110";
        if (ss == 'F')
            ans += "1111";
    }
    //去掉前导0
    int idx = 0;
    for (; idx < ans.size(); idx++)
    {
        if (ans[idx] == '1')
            break;
    }

    if (idx == ans.size())
        return "";
    return ans.substr(idx);
}

string cal(string a, string b) //算余数
{
    cout << a << ' ' << b << endl;
    string ans = "";
    for (int i = 0; i < a.size(); i++)
    {
        ans += to_string((a[i] - '0') ^ (b[i] - '0'));
    }
    //去掉前导0
    int idx = 0;
    for (; idx < ans.size(); idx++)
    {
        if (ans[idx] == '1')
            break;
    }
    if (idx == ans.size())
        return "";
    return ans.substr(idx);
}

void solve()
{
    string b, a;
    cin >> b >> a;
    int idx = 0;
    for (; idx < b.size(); idx++)
    {
        if (b[idx] == '1')
            break;
    }

    if (idx == b.size())
        idx--;
    b = b.substr(idx);
    a = tran(a);
    for (int i = 0; i < b.size() - 1; i++)
    {
        a = a + "0";
    }

    string cur = ""; //取得前i - 1位，这样每次循环就可以把要加的一位补上

    // cout << a << ' ' << b <<' '<< cur << endl;
    for (int i = 0; i < a.size(); i++)
    {
        while (i < b.size() - 1 && i < a.size())
        {
            cur += a[i];
            i++;
        }
        if (i < a.size())
        {
            cur += a[i];
            cur = cal(cur, b);
            if (cur.size() == b.size())
            {
                int as = 0;
                for (int i = 0; i < 1e18; i ++ )
                {
                    cout << "hi" << endl;
                }
                return;
            }
            while (i < a.size() && cur.size() < b.size() - 1)
            {
                i++;
                if (i < a.size())
                    cur += a[i];
            }
        }
    }

    int size = b.size() - 1 - cur.size();
    for (int i = 0; i < size; i++)
        cur = '0' + cur;
    cout << cur << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
}