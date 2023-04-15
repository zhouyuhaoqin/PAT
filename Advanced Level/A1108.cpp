/*
*	author:		zhouyuhao
*	created:	2023-04-01 19:46:31
*	modified:	2023-04-01 20:09:12
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>

using namespace std;

bool islaw(string s) {
	string t = s;
	if (s.find('.') != string::npos) {
		s.erase(s.find('.'), 1);
	}
	if (s.find('-') != string::npos) {
		s.erase(s.find('-'), 1);
	}
	for (int i = 0; i < s.size(); i++) {
		if (!isdigit(s[i])) {
			return false;
		}
	}
	double n = stod(t);
	if (n< -1000 || n > 1000) {
		return false;
	}
	int i = 0;
	while (i++ < t.size()) {
		if (t[i] == '.') {
			if (t.size() - i > 3) {
				return false;
			}
			break;
		}
	}
	return true;
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    double sum = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (!islaw(s)) {
        	cout << "ERROR: " << s << " is not a legal number\n";
        } else {
        	cnt++;
        	sum += stod(s);
        }
    }
    if (cnt == 0) {
    	cout << "The average of 0 numbers is Undefined\n";
    } else if (cnt == 1) {
    	cout << "The average of " << cnt << " number is " << fixed << setprecision(2) << sum / cnt << "\n";
    } else {
    	cout << "The average of " << cnt << " numbers is " << fixed << setprecision(2) << sum / cnt << "\n";
    }
    
    return 0;
}