/*
    Rating : 1200
    ֱ��ģ��ͺ��ˣ�ע��һ�����������֮ǰ����ΪҪȫ���꣬ʵ���ϳ�һ��Ҳ����
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int n, m, a, b;

    cin >> n >> m >> a >> b;
    if( b / m  < a)//���絥��Ʊ���ؼ�Ʊ�����˾Ͳ��ÿ�����
        cout << min( (n / m) * b + (n - n / m * m) * a, (n / m + 1) * b) << endl;
    else cout << a * n << endl;
    return 0;
}