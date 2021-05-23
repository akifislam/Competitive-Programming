#include <bits/stdc++.h>
using namespace std;
int n, p;
bool ok;
string s;
int main() {
	cin >> n >> p >> s;
	for (int i = 0; i < n - p; i++) {
		if(s[i] == '.' && s[i + p] == '.') {
			s[i] = '0';
			s[i + p] = '1';
			ok = true;
		}
		else if (s[i] == '.') {
			if(s[i + p] == '1')
				s[i] = '0';
			else
				s[i] = '1';
			ok = true;
		}
		else if (s[i + p] == '.') {
			if(s[i] == '1')
				s[i + p] = '0';
			else
				s[i + p] = '1';
			ok = true;
		}

		else if(s[i] != s[i + p])
			ok = true;
	}
    
	for (int i = 0; i < n; i++)
		if(s[i] == '.')
			s[i] = '0';
	if(ok)
		cout << s;
	else
		cout << "No";
	return 0;
}
