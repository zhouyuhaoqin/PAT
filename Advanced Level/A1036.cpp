/*
*	author:		zhouyuhao
*	created:	2023-03-22 20:51:31
*	modified:	2023-03-22 21:03:07
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	vector<string> ml(2), fh(2);
	int mlg = 101, fhg = -1;
	bool fm = false, ff = false;
	for (int i = 0; i < n; i++) {
		string name, gender, id;
		int grade;
		cin >> name >> gender >> id >> grade;
		if (gender == "M") {
			if (grade < mlg) {
				mlg = grade;
				ml[0] = name;
				ml[1] = id;
				fm = true;
			}
		} else {
			if (grade > fhg) {
				fhg = grade;
				fh[0] = name;
				fh[1] = id;
				ff = true;
			}
		}
	}
	if (ff) {
		cout << fh[0] << " " << fh[1] << "\n";
	} else {
		cout << "Absent\n";
	}
	if (fm) {
		cout << ml[0] << " " << ml[1] << "\n";
	} else {
		cout << "Absent\n";
	}
	if (ff && fm) {
		cout << fhg - mlg << "\n";
	} else {
		cout << "NA\n";
	}
	
	return 0;
}