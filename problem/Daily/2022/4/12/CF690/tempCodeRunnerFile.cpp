
    // vector<int> v(n + 1);
    // for (int i = 0, x; i < n; i++)
    // {
    //     cin >> x;
    //     v[x] ++;
    // }
    // int ans = 0;
    // cout << endl;
    // for (int i = 1; i <= n; i ++ )
    // {
    //     cout << v[i] << " \n"[i == n];
    //     if (i < n)
    //     {
    //         ans += v[i - 1] * v[i] * v[i + 1];
    //         ans += v[i] * (v[i] - 1) / 2 * v[i + 1];
    //         ans += v[i - 1] * v[i + 1] * (v[i + 1] - 1) / 2;
    //         ans += v[i + 1] * v[i - 1] * (v[i - 1] - 1) / 2;
    //     }
    //     ans += v[i - 1] * v[i] * (v[i] - 1) / 2;
    //     ans += v[i] * (v[i] - 1) * (v[i] - 2) / 6;
    // }
    // cout << ans << '\n';