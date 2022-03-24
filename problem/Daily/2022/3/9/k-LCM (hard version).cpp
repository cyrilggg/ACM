/*
    Rating : 1600
    思路：对于奇数，就(1, n / 2, n / 2)
    对于偶数，如果是4的倍数就(n / 4, n / 2, n / 2)
    如果不是就(2, n / 2 - 1, n / 2 - 1)
    只需要管3个数就好了
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> solve3(int n) {
    if (n % 2 == 1) return {1, n / 2, n / 2};
    if (n % 4 == 0) return {n / 2, n / 4, n / 4};
    if (n % 2 == 0) return {2, n / 2 - 1, n / 2 - 1};
}

int main() {
    int T;
    cin >> T;
    while (T --> 0) {
        int n, k;
        cin >> n >> k;
        vector<int> added = solve3(n - k + 3);
        for (int i = 0; i < k; ++i) {
            cout << (i <3 ? added[i] : 1) << ' '; // <3
        }
        cout << '\n';
    }
    return 0;
}