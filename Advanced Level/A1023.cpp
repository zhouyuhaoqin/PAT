/*
*	author:		zhouyuhao
*	created:	2023-04-11 15:27:24
*	modified:	2023-04-11 15:36:40
*	item:		Progrmming Ability Test
*	site:		Shahu, Yugan
*/
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

	string n1;
	cin >> n1;
	vector<int> cntn1(10);
	for (int i = 0; i < n1.size(); i++) {
		cntn1[n1[i] - '0']++;
	}
	string n2;
	int carry = 0;
	for (int i = n1.size() - 1; i >= 0; i--) {
		n2 = to_string(((n1[i] - '0') * 2 + carry) % 10) + n2;
		carry = ((n1[i] - '0') * 2 + carry) / 10;
	}
	if (carry != 0) {
		n2 = to_string(carry) + n2;
	}
	vector<int> cntn2(10);
	for (int i = 0; i < n2.size(); i++) {
		cntn2[n2[i] - '0']++;
	}
	if (cntn1 == cntn2) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
	cout << n2 << "\n";
	
	return 0;
}