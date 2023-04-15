/*
*	author:		zhouyuhao
*	created:	2023-04-11 21:33:00
*	modified:	2023-04-11 23:18:19
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

fra subtract(fra f1, fra f2) {
	fra r;
	r.num = f1.num * f2.den - f2.num * f1.den;
	r.den = f1.den * f2.den;
	return reduct(r);
}

fra multiply(fra f1, fra f2) {
	fra r;
	r.num = f1.num * f2.num;
	r.den = f1.den * f2.den;
	return reduct(r);
}

fra divide(fra f1, fra f2) {
	fra r;
	r.num = f1.num * f2.den;
	r.den = f1.den * f2.num;
	return reduct(r);
}

void print(fra r) {
	r = reduct(r);
	if (r.num < 0) {
		cout << "(";
	}
	if (r.den == 1) {
		cout << r.num;
	} else if (abs(r.num) > r.den) {
		cout << r.num / r.den << " " << abs(r.num) % r.den << "/" << r.den;
	} else {
		cout << r.num << "/" << r.den;
	}
	if (r.num < 0) {
		cout << ")";
	}
}

void printinf() {
	cout << "Inf";
}

int main(int argc, char const *argv[]) {

	fra a, b;
	scanf("%lld/%lld %lld/%lld", &a.num, &a.den, &b.num, &b.den);
	print(a), cout << " + ", print(b), cout << " = ", print(add(a, b)), cout << "\n";
	print(a), cout << " - ", print(b), cout << " = ", print(subtract(a, b)), cout << "\n";
	print(a), cout << " * ", print(b), cout << " = ", print(multiply(a, b)), cout << "\n";
	print(a), cout << " / ", print(b), cout << " = ", !b.num ? printinf() : print(divide(a, b)), cout << "\n";
	
	return 0;
}