/*
    Rating : 1600
    是看了题解才知道是状态机dp
    Dp[n][0] = Dp[n-1][0] + ... + Dp[n-min(d-1,n)][0] 
    Dp[n][1] = Dp[n-1][1] + ... + Dp[n-min(d-1,n)][1] + (Dp[n-d][0] + Dp[n-d][1]) + ... + (Dp[n-min(n,k)][0] + Dp[n-min(n,k)][1])
*/
#include <iostream>
#include <stdio.h>
#include <algorithm>
 
using namespace std;
 
const int mod = 1e9 + 7;
 
int dp[100][2];
 
void add(int &a, int b)
{
    a += b;
    if(a >= mod)
        a -= mod;
}
 
int main()
{
    int n, k, d;
    cin >> n >> k >> d;
    dp[0][0] = 1;
    dp[0][1] = 0;
    
    for(int i = 1 ; i <= n ; ++i)
    {
        dp[i][0] = dp[i][1] = 0;
        
        for(int j = 1 ; j <= k ; ++j)
        {
            if(i-j < 0) break;
            
            if(j < d)
            {
                add(dp[i][0], dp[i-j][0]);
                add(dp[i][1], dp[i-j][1]);
            }
            else
            {
                add(dp[i][1], dp[i-j][0]);
                add(dp[i][1], dp[i-j][1]);
            }
        }
    }
    cout << dp[n][1] << "\n";
    return 0;
}   