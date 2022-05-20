#include <bits/stdc++.h>
using namespace std;

int main()
{
    srand(time(0));
    int a, b, c;
    a = rand() % 100, b = rand() % 100, c = rand() % (a + b);
    cout << a << ' ' << b << ' ' << c << endl;
    return 0;
}