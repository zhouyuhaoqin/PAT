/*
*	author:		zhouyuhao
*	created:	2023-03-22 22:01:41
*	modified:	2023-03-31 15:56:16
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>

using namespace std;

long long trans(long long a, long long b, long long c) {
// long long trans(int a, int b, int c) {
	long long sum = a * 17 * 29 + b * 29 + c;
	return sum;
}

int main(int argc, char const *argv[]) {

	long long a, b, c;
	scanf("%lld.%lld.%lld", &a, &b, &c);
	// scanf("%d.%d.%d", &a, &b, &c);
	long long s1 = trans(a, b, c);
	scanf("%lld.%lld.%lld", &a, &b, &c);
	// scanf("%d.%d.%d", &a, &b, &c);
	long long s2 = trans(a, b, c);
	long long sum = s1 + s2;
	cout << sum / 17 / 29 << "." << sum / 29 % 17 << "." << sum % (17 * 29) % 29 << "\n";

	return 0;
}