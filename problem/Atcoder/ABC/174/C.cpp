#include <iostream>
using namespace std;

int main()
{
    int k;
    cin >> k;
    int op = k % 10;
    if(op == 0 || op == 2 || op == 4 || op == 5 || op == 6 || op == 8 || op == 9 ) cout << -1 <<endl;
    else
    {
        cout << k - 1 << endl;
    }
    return 0;
}