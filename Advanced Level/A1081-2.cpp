/*
*	author:		zhouyuhao
*	created:	2023-04-11 21:04:19
*	modified:	2023-04-11 21:05:09
*	item:		Progrmming Ability Test
*	site:		Shahu, Yugan
*/
#include <iostream>

using namespace std;

typedef long long int ll;

ll gcd(ll a, ll b) {
	if (b == 0) {
		return a;
	} else {
		return gcd(b, a % b);
	}
}

struct fra {
	ll num, den;
};

fra reduct(fra r) {
	if (r.den < 0) {
		r.num = -r.num;
		r.den = -r.den;
	}
	if (r.num == 0) {
		r.den = 1;
	} else {
		int g = gcd(abs(r.num), abs(r.den));
		r.num /= g;
		r.den /= g;
	}
	return r;
}

fra add(fra f1, fra f2) {
	fra r;
	r.num = f1.num * f2.den + f2.num * f1.den;
	r.den = f1.den * f2.den;
	return reduct(r);
}

void print(fra r) {
	r = reduct(r);
	if (r.den == 1) {
		cout << r.num << "\n";
	} else if (abs(r.num) > abs(r.den)) {
		cout << r.num / r.den << " " << abs(r.num) % r.den << "/" << r.den << "\n";
	} else {
		cout << r.num << "/" << r.den << "\n";
	}
}

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	fra sum = {0, 1}, temp;
	for (int i = 0; i < n; i++) {
		scanf("%lld/%lld", &temp.num, &temp.den);
		sum = add(sum, temp);
	}
	print(sum);
	
	return 0;
}