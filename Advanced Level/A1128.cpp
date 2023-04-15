/*
*	author:		zhouyuhao
*	created:	2023-04-03 09:43:15
*	modified:	2023-04-03 10:07:32
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool isqueen(vector<int> d) {
    bool flag = true;
    map<int, bool> row, diagonal;
    for (int i = 0; i < d.size(); i++) {
        if (row[d[i]] == false) {
            row[d[i]] = true;
        } else {
            flag = false;
            break;
        }
        if (diagonal[d[i] + i] == false) {
            diagonal[d[i] + i] = true;
        } else {
            flag = false;
            break;
        }
    }
    return flag;
}

int main(int argc, char const *argv[]) {

    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int n;
        cin >> n;
        vector<int> d(n);
        for (int j = 0; j < n; j++) {
            cin >> d[j];
        }
        if (isqueen(d)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}