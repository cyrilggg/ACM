/*
    Rating : 1200
    构造题 一个让全是1 一个让全是2
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t -- )
    {
        int n, k;
        cin >> n >> k;
        
            int tmp = n - k + 1;
            if (tmp > 0 && tmp & 1)
            {
                cout << "YES" << endl;
                for (int i = 1 ; i < k; i ++ )
                    cout << 1 << ' ';
                cout << tmp << endl;
                continue;
            }
            tmp = n - ( k - 1 ) * 2;
            if (tmp > 0 && (tmp & 1) == 0)
            {
                cout << "YES" << endl;
                for (int i = 1; i < k; i ++ )
                    cout << 2 << ' ';
                cout << tmp << endl;
                continue;
            }
            cout << "NO" << endl;
        
    }
    return 0;
}