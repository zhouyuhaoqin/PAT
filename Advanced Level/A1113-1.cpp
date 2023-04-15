/*
*	author:		zhouyuhao
*	created:	2023-04-02 09:54:07
*	modified:	2023-04-02 10:20:46
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    vector<int> d(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> d[i];
        sum += d[i];
    }
    sort(d.begin(), d.end());
    int pivot = n / 2 - 1;
    int suml = 0;
    for (int i = 0; i <= pivot; i++) {
        suml += d[i];
    }
    if (n % 2 == 0) {
        cout << "0 ";
    } else {
        cout << "1 ";
    }
    cout << sum - 2 * suml << "\n";
    
    return 0;
}