/*
    Rating : 1200
    这题有非常多的tag 看来可以用 dp ,双指针 等等去做，不过没有研究
    看着题目就是两个数组的匹配，下意识就想到二分图匹配，用匈牙利板子就可以过了。。。O(n^2)
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 110,M=1e5+10;
int n1,n2,m;
int match[N];
bool st[N];
int a[N],b[N];

bool find(int x)
{
    for (int i = 1; i <= n2; i ++ )
    {
       if(!st[i] && (b[i] == a[x] || b[i] == a[x] + 1 || b[i] == a[x] - 1))
       {
           st[i]=true;
           if(match[i]==0||find(match[i]))
           {
               match[i]=x;
               return true;
           }
       }
    }
   return false;
}



int main()
{

    cin >> n1;
    for (int i = 1; i <= n1; i ++ ) cin >> a[i];
    cin >> n2;
    for (int i = 1; i <= n2; i ++ ) cin >> b[i];

    int res=0;
    for (int i = 1; i <= n1; i ++ )
    {
        memset(st, 0, sizeof st);
        if(find(i))
        {
            res++;
        }
    }
    cout << res << endl;
}