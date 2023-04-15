/*
*	author:		zhouyuhao
*	created:	2023-04-02 22:35:40
*	modified:	2023-04-02 22:50:15
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <map>
#include <cmath>

using namespace std;

bool isprime(int n) {
    if (n <= 1) {
        return false;
    }
    // if (n == 1 || n == 2) {
    //     return true;
    // }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    map<string, int> r;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        r[s] = i + 1;
    }
    int k;
    cin >> k;
    map<string, int> c;
    for (int q = 0; q < k; q++) {
        string s;
        cin >> s;
        cout << s << ": ";
        if (c[s] != 0) {
            cout << "Checked\n";
        } else {
            if (r[s] == 0) {
                cout << "Are you kidding?\n";
            } else if (r[s] == 1) {
                c[s]++;
                cout << "Mystery Award\n";
            } else if (isprime(r[s])) {
                c[s]++;
                cout << "Minion\n";
            } else {
                c[s]++;
                cout << "Chocolate\n";
            }
        }
    }
    
    return 0;
}