/*
*	author:		zhouyuhao
*	created:	2023-03-22 16:15:09
*	modified:	2023-03-22 16:23:30
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <iomanip>
#define CLK_TCK 100

using namespace std;

int main(int argc, char const *argv[]) {

	int c1, c2;
	cin >> c1 >> c2;
	int sec = (c2 - c1) * 1.0 / CLK_TCK + 0.5;
	int h = sec / 60 / 60;
	int m = sec % (60 * 60) / 60;
	int s = sec % 60;
	cout << setfill('0') << setw(2) << h << ":";
	cout << setfill('0') << setw(2) << m << ":";
	cout << setfill('0') << setw(2) << s << "\n";
	
	return 0;
}