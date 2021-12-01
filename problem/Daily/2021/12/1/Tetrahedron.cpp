/*
    Rating : 1500
    dp �� �� �����������߻ض����·������˼·��ʼû�Ƴ������һ�����ϣ����Թ�������dp��һ�����߻ص�����ķ�����f��һ�����ߵ��Ƕ���ķ�����������
    f(i) = 3 * g(i - 1), g(i) = f(i - 1) + 2 * g(i)
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int mod = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    int f = 0, g = 1;
    for (int i = 2; i <= n; i ++ )
    {
        int tmp = f;
        f = (3 * g) % mod, g = (tmp + 2 * g) % mod;
    }
    cout << f << endl;
	return 0;
}