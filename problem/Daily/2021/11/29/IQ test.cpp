/*
    Rating : 1200
    ���⣬�����ʵ�ֻ��һ���������������±��Ƕ��٣�����ֻ��һ��ż����ż�����±��Ƕ��٣��򵥴�һ�¼���
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
 
int n;
int ocnt, oidx, eidx, ecnt;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++ )
    {
        int x;
        cin >> x;
        if(x & 1)
        {
            oidx = i;
            ocnt ++;
        }
        else
        {
            eidx = i;
            ecnt ++;
        }
    }
    if(ocnt == 1)
    {
        cout << oidx <<endl;
    }
    else cout << eidx << endl;
    return 0;
}