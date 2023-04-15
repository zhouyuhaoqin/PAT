/*
*	author:		zhouyuhao
*	created:	2023-04-03 01:51:08
*	modified:	2023-04-03 01:55:56
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <set>

using namespace std;

int trans(int n) {
    int sum = 0;
    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    set<int> ans;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        ans.insert(trans(num));
    }
    int size = ans.size();
    cout << size << "\n";
    for (auto it : ans) {
        cout << it;
        if (--size > 0) {
            cout << " ";
        } else {
            cout << "\n";
        }
    }
    
    return 0;
}