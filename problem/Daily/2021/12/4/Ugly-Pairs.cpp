/*
    Rating : 1800
    做的时候尝试了各种构造，最后是看tutorial的，同样是奇偶构造，但是能想到是按照字典序奇偶就很强
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

bool check(string s){
	bool ok = true;
	for (int i = 0; i < s.size(); i ++ )
		ok &= (abs(s[i] - s[i + 1]) != 1);
	return ok;
}

int main() {
	int t;
	cin >> t;
	while (t -- )
    {
        string a;
		cin >> a;
		string s = a;
		string odd = "", even = "";
		for (int i = 0; i < s.size(); i ++ )
		{
			if (s[i] % 2 == 0)
				odd += s[i];
			else
				even += s[i];
		}
		sort(odd.begin(), odd.end());
		sort(even.begin(), even.end());
		if (check(odd + even))
			cout << odd + even <<endl;
		else if (check(even + odd))
			cout << even + odd <<endl;
		else
			puts("No answer");
	}
	return 0;
}