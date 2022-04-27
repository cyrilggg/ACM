#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define returnNo return void(puts("No"))
#define returnYes return void(puts("Yes"))
const int N = 2e5 + 10;
int st[N];
int top;
void solve()
{
    top = 0;
    int n;
    cin >> n;
    vector<int>A(n + 1), B(n + 1);
    for (int i = 1; i <= n; i ++ ){
        cin >> A[i];
    }
    for (int i = 1; i <= n; i ++ ){
        cin >> B[i];
    }
    map<int,int>mp;
    vector<int>ans;
    ans.push_back(0);
    for (int i = 1, j = 1; i <= n && j <= n; i ++, j ++ ){
        if (mp[B[j]] > 0){
                ans.push_back(B[j]);
                mp[B[j]] --;
                i --;
                continue;
            }
        if (A[i] != B[j]){
            while (i <= n && A[i] != B[j]){
                mp[A[i]] ++;
                //if (mp[A[i]] == 2) returnNo;
                i ++;
            }
            if (i > n) break;
            ans.push_back(A[i]); 
        }
        else{
            ans.push_back(A[i]);
        }
    }
    //for (int i = 1; i <= n; i ++ ) cout << ans[i] << " \n"[i == n];
    for (int i = 1; i <= n; i ++ ){
        if (ans[i] != B[i]) returnNo;
    }
    returnYes;
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