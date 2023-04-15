/*
*	author:		zhouyuhao
*	created:	2023-04-03 02:45:36
*	modified:	2023-04-03 02:54:28
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[]) {

    int m, n, st;
    cin >> m >> n >> st;
    int cnt = 0;
    bool nowinner = true;
    map<string, bool> iswinner;
    for (int i = 1; i <= m; i++) {
        string s;
        cin >> s;
        if (i >= st) {
            if (!iswinner[s]) {
                if (cnt % n == 0) {
                    cout << s << "\n";
                    nowinner = false;
                    iswinner[s] = true;
                }
                cnt++;
            }
        }
    }
    if (nowinner) {
        cout << "Keep going...\n";
    }
    
    return 0;
}